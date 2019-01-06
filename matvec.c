#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* return y = Ax */
int *matvec(int **A, int *x, size_t n) {
  if (n == 0 || n > SIZE_MAX / sizeof(int))	
	return NULL; // n is either too large for calloc or 0
  int *y = (int *)calloc(n, sizeof(int)); // calloc initializes to zero
  if (y == NULL)
    return NULL; // calloc failed when generating the y vector to hold the product
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      y[i] += A[i][j] * x[j];
  return y;
}


/*
n, which represents the length of the the x vector and that of each row of A, 
should be a size_t, not an int.

Need to prevent unsigned integer wrap in the call to calloc by checking
if n > SIZE_MAX / sizeof(int). If so, then n would be at least 16384, which
leads to wrap when mutiplied by sizeof(int) == 4.

We need to check the return value of calloc to ensure that the memory
allocation function succeeded and return NULL if it didn't.

Not sure if the matvec function should be responsible for checking if
A and x are valid pointers...

*/