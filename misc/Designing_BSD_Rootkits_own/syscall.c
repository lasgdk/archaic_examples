#include <sys/types.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/module.h>
#include <sys/sysent.h>
#include <sys/kernel.h>
#include <sys/systm.h>

struct syscall_args_struct{
	char *str;
};

static int syscall_example(struct thread *td, void *syscall_args){
	struct syscall_args_struct *uap;
	uap = (struct syscall_args_struct *)syscall_args;

	printf("%s\n",uap->str);

	return(0);
}

static struct sysent syscall_sysent = {
	1,
	syscall_example
};

static int offset = NO_SYSCALL;

static int load(struct module *module, int cmd, void *arg){
	int error=0;
	switch(cmd){
		case MOD_LOAD:
			uprintf("System call at offset %d is loaded!\n",offset);
			break;
		case MOD_UNLOAD:
			uprintf("System call at offset %d is UNloaded!\n",offset);
			break;
		default:
			error=EOPNOTSUPP;
			break;
	}
	return error;
}

SYSCALL_MODULE(syscall_example, &offset,&syscall_sysent,load,NULL);



