#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *envstr; // represents the latest return value of getenv()
	char *tmpvar; // saved TMP string
	char *tempvar; // saved TEMP string
	
	// get and store "TMP"'s value
	envstr = getenv("TMP");
	if (!envstr) return -1;
	tmpvar = strdup(envstr);
	printf("TMP = %s\n", tmpvar);
	
	// get and store "TEMP"'s value
	envstr = getenv("TEMP");
	if (!envstr) return -1;
	tempvar = strdup(envstr);
	printf("TEMP = %s\n", tempvar);

	if (strcmp(tmpvar, tempvar) == 0) {
	  if (puts("TMP and TEMP are the same.\n") == EOF) {
		/* Handle error */
		puts("puts error");
	  }
	}
	else {
	  if (puts("TMP and TEMP are NOT the same.\n") == EOF) {
		/* Handle error */
		puts("puts error");
	  }
	}
	free(tempvar); // caller is responsible for freeing memory allocated by strdup
	free(tmpvar);
}
