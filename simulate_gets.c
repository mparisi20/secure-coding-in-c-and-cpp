#include <stdio.h>
#include <string.h>

#define LINE_MAX 15
char buf[LINE_MAX];
int ch;
char *p;
 
/* Get a line of data from stdin. Behaves like gets()
in that the trailing newline is replaced with a null byte,
but this implementation puts a limit on the amount of data that can 
be read, and it flushes the rest of the line out of stdin
if the line does not fit in the destination buffer. */

int main(void) {
	if (fgets(buf, sizeof(buf), stdin)) {
		/* fgets succeeds, scan for newline character */
		p = strchr(buf, '\n');
		if (p) {
			*p = '\0';
			}
		else {
			/* newline not found, flush stdin to end of line */
			while (((ch = getchar()) != '\n')
				&& !feof(stdin)
				&& !ferror(stdin)
			); // end while loop
		}
	}
	else {
	  /* fgets failed, handle error */
	  puts("fgets failed. An empty file may have been provided");
	  return 1;
	}
	printf("%s\n", buf);
	return 0;
}
