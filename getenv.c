#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	const char *envstr; // represents the latest return value of getenv()
	char *tmpvar; // saved TMP string
	char *tempvar; // saved TEMP string
	
	// get and store "TMP"'s value, with robust error checking
	envstr = getenv("TMP");
	if (!envstr) {
		puts("getenv failed: no match found");
		return -1;
	}
	tmpvar = strdup(envstr);
	if (!tmpvar) {
		puts("strdup failed.");
		return -1;
	}
	printf("TMP = %s\n", tmpvar);
	
	// get and store "TEMP"'s value, with robust error checking
	envstr = getenv("TEMP");
	if (!envstr) {
		puts("getenv failed: no match found");
		free(tmpvar);
		tempvar = NULL;
		return -1;
	}
	tempvar = strdup(envstr);
	if (!tempvar) {
		puts("strdup failed.");
		free(tmpvar);
		tmpvar = NULL;
		return -1;
	}
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
	tempvar = NULL;
	free(tmpvar);
	tmpvar = NULL;
}
