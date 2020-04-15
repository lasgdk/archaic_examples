        .data
        .global _start

_start:
        popl    %ebx                    # don't want argc
        popl    %ebx                    # don't want argv[0] either

get_args:
        popl    %ebx                    # pop our next argument
        movl    %ebx,%edx               # save our string in %edx
        or      %ebx,%ebx               # check if zero, the last arg
        jz      exit                    # if true, exit
        movl    $0,%ecx                 # set our counter to 0
        
getlen:
        movb    (%ebx),%al              # move 1 byte of st to %al
        incl    %ecx                    # increment our string size counter 
        incl    %ebx                    # move to the next byte in string
        or      %al,%al                 # check if current byte is zero (NULL)
        jnz     getlen                  # if not zero, run getlen again
        movb    $0x20,-1(%ebx)           # replace the NULL at then end of the
                                        #       string with a LF, Line Feed 

write:
        pushl   %ecx                    # push number of bytes in our string. 
        pushl   %edx                    # push the string
        pushl   $1                      # push our file descriptor, STDOUT
        movl    $4,%eax                 # setup our syscall for write() 
        call    kernel                  # call kernel to execute syscall
        addl    $12,%esp                # Clean stack
        jmp     get_args                # run the get_args procedure again. 

newl:	.asciz	"\n"

exit:
        pushl   $1                    # push number of bytes in our string. 
        pushl   $newl                    # push the string
        pushl   $1                      # push our file descriptor, STDOUT
        movl    $4,%eax                 # setup our syscall for write() 
        call    kernel                  # call kernel to execute syscall
        addl    $12,%esp                # Clean stack

        pushl   $0                      # push our exit status
        movl    $1,%eax                 # move the value '1' into %eax: exit()
        call    kernel                  # call kernel, execute syscall

kernel:                                 # call the kernel       
        int     $0x80
        ret

