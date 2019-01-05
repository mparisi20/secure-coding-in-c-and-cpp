#include <alloca.h> // only available on some GCC/Linux/BSD systems

int func(int n)
{
	int *ptr = (int *)alloca(sizeof(int));
	*ptr = n;
	int res = *ptr++;
	return res; // no need to free ptr... alloca allocates on the stack, so it's automatically deallocated upon function return.
}
int main(void)
{
	func(15);
	return 0;
}
