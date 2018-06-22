#ifndef KEYBINDINGS_H
#define KEYBINDINGS_H

#include <uthash.h>

#define MAX_KEY_LENGTH 50
#define MAX_COMMAND_LENGTH 200

/**
 * A single keybinding structure
 */
struct Keybinding {
	char key[MAX_KEY_LENGTH];
	char command[MAX_COMMAND_LENGTH];
	UT_hash_handle hh;
};

static struct Keybinding *keybindings = NULL;

/**
 * Adds a keybinding to a table
 */
void add_keybinding(char *key, char *command);

/**
 * Finds a keybinding from a key
 */
struct Keybinding *find_keybinding(char *key);

/**
 * Deletes a keybinding from a keybinding table
 */
void delete_keybinding(struct Keybinding *keybinding);

/**
 * Iterates over the keybindings array calling the function f with the key and 
 * command being the two arguments that are passed to the function.
 *
 * Arguments:
 *	f - The function to call with the key and command being arguments of the 
 *	function.
 */
void iterate_keybindings(void (*f)(char *key, char *command));

#endif
