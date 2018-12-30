#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum limits { USERNAME_LEN=20, PASSWORD_LEN=100 };

typedef struct ut {
  char username[USERNAME_LEN];
  char password[PASSWORD_LEN];
  struct ut *next;
} user_type;

user_type *User_List = NULL;

/* Adds username/password to User_List.
Returns nonzero if successful */
int add(const char *username, const char *password) {
	user_type *new_node = malloc(sizeof(user_type));
	if (new_node == NULL)
		return 0;
	if (strlen(username) >= USERNAME_LEN) {
		printf("Username must be shorter than %d characters", USERNAME_LEN);
		return 0;
	}
	if (strlen(password) >= PASSWORD_LEN) {
		printf("Password must be shorter than %d characters", PASSWORD_LEN);
		return 0;
	}
	strcpy(new_node->username, username);
	strcpy(new_node->password, password);
	new_node->next = User_List;
	User_List = new_node;
	return 1;
}

int main(void) {
	add("User", "pass");
	return 0;
}

