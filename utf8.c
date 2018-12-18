#include <stdio.h>
#include <string.h>

int spc_utf8_isvalid(const unsigned char *);
int main(void)
{
	unsigned char input[4]; // U+00A2... 000 1010 0010
	input[0] = 0b11000010; // binary prefix 0b is a GNU extension
	input[1] = 0b10100010;
	input[2] = 0b10000000; // makes this an invalid UTF-8 string... expecting beginning of a new character here, but got continuation byte
	input[3] = 0;
	printf("%s\n", input);
	
	int res = 100;
	res = spc_utf8_isvalid(input);
	printf("%d\n", res);
	
	unsigned char b = 0xff;
	int c = b;
	printf("%d\n", c); // zero-extended
	printf("%x\n", 'a'); // 
	
	const int *str = "hello world!"; // compiler warns about putting a char * into an int * (K&R says this is illegal, but it compiles)
	printf("%x\n", str[0]); // prints hex values "lleh" due to little endian format (probably UB)
	
	char str2[10];
	sprintf(str2, "%.3stest\n", str);
	printf("%s\n", str2); // 3 bytes from str, 4 bytes from "test", then null byte
	
	return 0;
}

int spc_utf8_isvalid(const unsigned char *input) {
  int nb; // number of additional bytes in the case of a multibyte character 
  const unsigned char *c = input; // retrieve string of bytes and check if they represent valid UTF-8 characters
 
  for (c = input;  *c;  c += (nb + 1)) {
    if (!(*c & 0x80)) nb = 0; // if the first bit is 0, aka ASCII single byte
    else if ((*c & 0xc0) == 0x80) return 0; // if the first two bits are '10', it must be invalid (should be the beginning of a new sequence)
    else if ((*c & 0xe0) == 0xc0) nb = 1; // if the first three bits are '110', it must be the beginning of a two-byte character
    else if ((*c & 0xf0) == 0xe0) nb = 2; // if the first four bits are '1110', must be beginning of a three-byte char
    else if ((*c & 0xf8) == 0xf0) nb = 3; // if the first five bits are '11110', must be start of four-byte char
    else if ((*c & 0xfc) == 0xf8) nb = 4; // ... '111110' five byte char
    else if ((*c & 0xfe) == 0xfc) nb = 5; // ... '1111110' six byte char
	int temp = nb; // copy nb to temp so we don't need to modify nb's value
    while (temp > 0) {
      if ((*(c + temp) & 0xc0) != 0x80) return 0; // this does not check for shortest forms! as long you have, e.g., '110xxxxx' '10xxxxxx' for a two-byte char, it accepts it!
	  temp--;
	}
  }
  return 1;
}
