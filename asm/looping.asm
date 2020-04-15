string:         .asciz "Looping!\n"
                len = . - string - 1

        .text
        .global _start

_start:
        movl    $0,%ecx                 # set the inital counter value

compare:
        cmpl    $9,%ecx                 # compare to what is in %ecx
        jle     write                   # call if less than or equal
        jmp     exit                    # otherwise, exit

write:
        pushl   $len                   # push length of string
        pushl   $string                 # push the string
        pushl   $1                      # push the file descriptor
        movl    $4,%eax                 # move the value '4' into %eax: write()
        call    kernel                  # call kernel, execute syscall
        addl    $12,%esp                # clean stack
        jmp     increment               # jump to the increment procedure

increment:
        incl    %ecx                    # increment the value in %ecx by 1
        jmp     compare                 # jump back to the compare procedure

exit:
        pushl   $0                      # push our exit status
        movl    $1,%eax                 # move the value '1' into %eax: exit()
        call    kernel                  # call kernel, execute syscall

kernel:                                 # call the kernel
        int     $0x80
        ret
