#include <string.h>
#include "keybindings.h"

void add_keybinding(char *key, char *command) {
	struct Keybinding *keybinding;

	keybinding = malloc(sizeof(struct Keybinding));
	strcpy(keybinding->key, key);
	strcpy(keybinding->command, command);
	HASH_ADD_STR(keybindings, key, keybinding);
}

struct Keybinding *find_keybinding(char *key) {
	struct Keybinding *keybinding;

	HASH_FIND_STR(keybindings, key, keybinding);
	return keybinding;
}

void delete_keybinding(struct Keybinding *keybinding) {
	HASH_DEL(keybindings, keybinding);
	free(keybinding);
}

void iterate_keybindings(void (*f)(char *key, char *command)) {
	struct Keybinding *k;

	for (k = keybindings; k != NULL; k = k->hh.next) {
		f(k->key, k->command);
	}
}
