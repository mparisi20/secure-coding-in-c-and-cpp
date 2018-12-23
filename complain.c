#include <string.h>
#include <stdio.h>

errno_t complain(const char *msg) {
  static const char prefix[] = "Error: ";
  static const char suffix[] = "\n";
  char buf[BUFSIZ];
  errno_t error = 0;
  // strcpy_s and strcat_s return 0 on success and nonzero value on failure
  
  if (error = strcpy_s(buf, BUFSIZ, prefix)) {
	puts("error copying prefix into buf");
	return error;
  }
  if (error = strcat_s(buf, BUFSIZ, msg)) {
	puts("error attaching msg to buf");
	return error;
  }
  if (error = strcat_s(buf, BUFSIZ, suffix)) {
	puts("error attaching suffix to buf");
	return error;
  }
  return fputs(buf, stderr);
}

int main(void) {
  constraint_handler_t oconstraint =
     set_constraint_handler_s(ignore_handler_s);
  get_y_or_n();
}
