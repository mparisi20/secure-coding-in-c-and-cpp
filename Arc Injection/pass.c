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
	//system("\\Windows\\write"); // just an example system call... The arc injection will write the parameter ".\attack" onto the stack
	return 0;
}
