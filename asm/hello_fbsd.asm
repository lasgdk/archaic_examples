#hello world for freebsd
#2005-07-28 lasg@lasg.dk 

 
	.data           # Data Section

msg:    .asciz "hello world\n" # Our String
        
        len = . - msg -1               # the length of the string

        .text
        .global _start 

_start:                         # Program Entry Point.
        pushl   $len            # Arg 3 to write: length of string.
        pushl   $msg            # Arg 2: pointer to string.
        pushl   $1              # Arg 1: file descriptor (STDOUT)
        movl    $4,%eax         # Write.  Move the syscall number into %eax
        call    syscall         # Call Kernel 
        addl    $12,%esp        # Clean stack.
        pushl   $0              # Exit status.
        movl    $1,%eax         # Exit.
        call    syscall 

syscall:                        # Our syscall subroutine to call Kernel 
        int     $0x80           # Call Kernel
        ret

