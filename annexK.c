#define __STDC_WANT_LIB_EXT1__ 1 // not working; my MinGW doesn't include the Annex K extension
#include <stdio.h>
#include <stdlib.h>

void get_y_or_n(constraint_handler_t oconstraint) {
  char response[8];
  size_t len = sizeof(response);
  set_constraint_handler_s(ignore_handler_s); // this makes the gets_s function simply return a NULL pointer if src is too large
  printf("Continue? [y] n: ");
  if ((gets_s(response, len) == NULL) || (response[0] == 'n')) {
    exit(0);
  }
  set_constraint_handler_s(oconstraint); // restore original constraint handler before returning to main
  return;
}

int main(void) {
  constraint_handler_t oconstraint =
     set_constraint_handler_s(ignore_handler_s); // this could be any handler now
  get_y_or_n(oconstraint); // pass constraint to get_y_or_n so this function can customize the handler and still restore it before returning
}

