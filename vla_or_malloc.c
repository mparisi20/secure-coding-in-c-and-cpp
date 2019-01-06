#include <stdint.h>
#include <stdlib.h>

enum { MAX_ARRAY = 1024 };

extern void do_work(int *array, size_t size);
void func(size_t size) { // size could be any value from 0 to SIZE_MAX (65535)
  if (0 == size || SIZE_MAX / sizeof(int) < size) {
    /* Handle error */
    return;
  }
  // Now we know 1 <= size <= 16383
  if (size < MAX_ARRAY) { // size is sufficiently small, so we choose to allocate on the stack using a VLA
    int vla[size];
    do_work(vla, size);
  } else { // Now we know 1024 <= size <= 16383, so we resort to malloc, knowing that an unsigned wrap will not occur in the call to it
    int *array = (int *)malloc(size * sizeof(int)); // 4096 <= (size * sizeof(int)) <= 65532... No chance of overflow
    if (array == NULL) {
      /* Handle error */
    }
    do_work(array, size);
    free(array);
  }
}