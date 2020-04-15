        .data

string1:        .asciz "createfile"                    # Output file
string2:        .asciz "AAAAAAAAAA"                     # Chars to write

                len_str1 = . - string1 - 1              # set len of string1
                len_str2 = . - string2 - 1              # set len of string2

        .text
        .global _start

_start:
        # Procedure for open()
        pushl   $0x601          # Flags for open(): O_CREAT O_TRUNC O_WRONLY
        pushl   $string1        # the file name to create and open
        movl    $5,%eax         # move '5' into %eax for open() syscall
        call    kernel          # call the kernel, execute our syscall
        mov     %eax,%ebx       # Save our file descriptor in %ebx
        xorl    %eax,%eax       # Clear the %eax register
        addl    $8,%esp         # 2 args pushed, both 4 bytes long
        
        # Procedure for chmod() 
        pushl   $0x1a4          # Flags we are going to pass to chmod() hex
        pushl   $string1        # the file name to chmod()
        movl    $15,%eax        # move '15' into %eax for chmod() syscall
        call    kernel          # call the kernel, execute the syscall
        xorl    %eax,%eax       # Clean our %eax register
        addl    $8,%esp         # Again, clean stack    
        
        # Procedure for write() to our file     
        pushl   $len_str2       # The number of bytes to write to our file
        pushl   $string2        # Or little buffer of char's
        push    %ebx            # our file descriptor
        movl    $4,%eax         # move '4' into %eax for write() syscall
        call    kernel          # call the kernel, execute the syscall
        xorl    %eax,%eax       # Clean our %eax register
        addl    $12,%esp        # again, clean the stack
        pushl   $0              # our exit status
        movl    $1,%eax         # move '1' into %eax for exit() syscall
        call    kernel  

kernel:                         # Call the Kernel 
        int     $0x80
        ret
