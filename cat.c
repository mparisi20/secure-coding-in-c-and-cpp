#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a = 25;
	printf("a"
		   "b" 
		   "c%d" 
		   "\n", a); // C automatically concatenates string literals
	printf("sizeof('a') == %d, sizeof(wchar_t) == %d, sizeof(\"abcdef\") == %d\n", 
		sizeof('a'), 
		sizeof(wchar_t), 
		sizeof("abcdef\n")); // in C, character constants are **ints**, not chars!
		
	printf("wide characters take up 2 bytes (Windows encodes with UTF-16)\n");
	const wchar_t wide_str1[] = L"0123456789";
	wchar_t *wide_str2 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t));
	printf("%d\n", (wcslen(wide_str1) + 1) * sizeof(wchar_t));
	wcscpy(wide_str2, wide_str1); // (dest, source)
	if (wide_str2 == NULL) {
	/* handle error */
	}
	wprintf(L"%s\n%s\n", wide_str1, wide_str2);
	free(wide_str2);
	wide_str2 = NULL;
}

