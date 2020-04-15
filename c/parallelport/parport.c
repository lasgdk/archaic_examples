/* pioexample.c         Example of using PIO to talk to an I/O port
 *
 * Little ditty to count bits on the parallel port output register.
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <machine/sysarch.h>
#include <machine/bus_pio.h>

/* ioport(port)         permit access to an I/O port.
 * port                 I/O address to enable
 */
void
ioport(int port) {
        u_long iomap[32];
        struct i386_set_ioperm_args ioperm;
 
        ioperm.iomap = iomap;
        syscall(SYS_sysarch, I386_GET_IOPERM, (char *) &ioperm);
        iomap[port >> 5] &= ~(1 << (port & 0x1f));
        syscall(SYS_sysarch, I386_SET_IOPERM, (char *) &ioperm);
}

int
main() {
        int i;
        ioport(0x378);                  /* Enable access to the port */
        for(i = 0; i < 256; i++) {
                outb(0x378, i);         /* Set the output register   */
                sleep(1);               /* Sleep a tick              */
        }
        return 0;
}

