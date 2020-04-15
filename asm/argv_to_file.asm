        .data
filename:	.asciz "argv_to_file.txt"
len_filename =	. - filename -1

	.text
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

        # Procedure for open()
        pushl   $0x808          # Flags for open(): O_CREAT O_TRUNC O_WRONLY
        pushl   $filename        # the file name to create and open
        movl    $5,%eax         # move '5' into %eax for open() syscall
        call    kernel          # call the kernel, execute our syscall
        mov     %eax,%ebx       # Save our file descriptor in %ebx
        xorl    %eax,%eax       # Clear the %eax register
        addl    $8,%esp         # 2 args pushed, both 4 bytes long
        
        # Procedure for chmod() 
        pushl   $0x1a4          # Flags we are going to pass to chmod() hex
        pushl   $filename        # the file name to chmod()
        movl    $15,%eax        # move '15' into %eax for chmod() syscall
        call    kernel          # call the kernel, execute the syscall
        xorl    %eax,%eax       # Clean our %eax register
        addl    $8,%esp         # Again, clean stack    

        pushl   %ecx       # The number of bytes to write to our file
        pushl   %edx        # Or little buffer of char's
        pushl    %ebx            # our file descriptor
        movl    $4,%eax         # move '4' into %eax for write() syscall
        call    kernel          # call the kernel, execute the syscall
        xorl    %eax,%eax       # Clean our %eax register
        addl    $12,%esp        # again, clean the stack
        jmp     get_args                # run the get_args procedure again. 

	pushl	%ebx
	movl	$5,%eax
	call	kernel	
 

newl:	.asciz	"\n"

exit:
        pushl   $0                      # push our exit status
        movl    $1,%eax                 # move the value '1' into %eax: exit()
        call    kernel                  # call kernel, execute syscall

kernel:                                 # call the kernel       
        int     $0x80
        ret

