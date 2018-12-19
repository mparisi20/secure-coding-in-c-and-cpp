#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s1[] = "012345678";
	char s2[] = "0123456789";
	char *dest;
	int i;
	
	// (strcpy_s is a windows CRT function similar to strlcpy)

	//strcpy_s(s1, sizeof(s2), s2); // off by one error here, because the nullbyte of s2 is written into s1[10], an undefined location
	dest = (char *)malloc(strlen(s1)); // allocates 9 bytes for dest (possibly 10 due to undefined strcpy from previous line?)
	for (i=1; i <= 11; i++) {
		dest[i] = s1[i]; // writes in dest[9], dest[10], and dest[11] and reads s1[10] and s1[11], all undefined behaviors
	} // we also never initialize dest[0], to the printf is undefined, too
	dest[i] = '\0'; // writes to dest[12], an undefined location
	printf("dest = %s\n", dest); // uninitialized dest[0] makes this undefined
	/* ... */;
	
	char a[16];
	char b[16];
	char c[16];
	strncpy(a, "0123456789abcdef", sizeof(a)); // no null terminator
	strncpy(b, "0123456789abcdef", sizeof(b)); // no null terminator
	strcpy(c, a); // undefined behavior
	printf("%s\n", c); // UB. My compiler happens to put s2's data right after c's, so this prints 0123456789abcdef0123456789
}
