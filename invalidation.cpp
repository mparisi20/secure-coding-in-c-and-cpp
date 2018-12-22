#include <iostream>
#include <string>

char input[];
string email;
string::iterator loc = email.begin();
// copy into string converting ";" to " "
for (size_t i=0; i < strlen(input); ++i) {
  if (input[i] != ';') {
	// email.insert(loc++, input[i]);  INCORRECT... reuses the loc iterator, which is invalidated after the first insert
	loc = email.insert(loc, input[i]); // correct
  }
  else loc = email.insert(loc, ' ');
  // email.insert(loc++, ' ');	INCORRECT for the same reason as above
  ++loc; // increment only after you've gotten a valid loc
}
