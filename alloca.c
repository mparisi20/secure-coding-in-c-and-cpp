// #include <alloca.h> // only available on some GCC/Linux/BSD systems
#include <stdio.h>
#include <stddef.h>
/*
int func(int n)
{
	int *ptr = (int *)alloca(sizeof(int));
	*ptr = n;
	int res = *ptr++;
	return res; // no need to free ptr... alloca allocates on the stack, so it's automatically deallocated upon function return.
}
*/

void vla(size_t size) // giving an excessive size can lead to a security vulnerability
{
	int a[size+10];
	puts("This implementation supports VLAs");
	return;
}

int main(void)
{
	vla(10);
	
	return 0;
}
