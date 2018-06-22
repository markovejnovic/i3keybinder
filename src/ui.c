#include <string.h>
#include "ui.h"
#include "stringdefs.h"
#include "keybindings.h"

static WindowProperties stdscrProps;

void initUi() {
	initscr();
	curs_set(FALSE);
	clear();
	refresh();

	// Assume that x0 and y0 are zero for stdscr
	stdscrProps.x0 = 0;
	stdscrProps.y0 = 0;
	stdscrProps.w = getmaxx(stdscr);
	stdscrProps.h = getmaxy(stdscr);
}

int drawHeader() {
	mvprintw(stdscrProps.y0, 
		(stdscrProps.w - strlen(APP_TITLE_STRING)) / 2,
		APP_TITLE_STRING);
	mvprintw(stdscrProps.y0 + 1,
		(stdscrProps.w - strlen(APP_AUTHOR_STRING)) / 2,
		APP_AUTHOR_STRING);

	refresh(); // TODO Remove
	return 2;
}

/**
 * This function is only used so that iterate_keybindings has a function to 
 * call.
 */
int elementY, elementX;
void drawKeybindingElement(char *key, char *command) {
	mvprintw(elementY, elementX, key);
	mvprintw(elementY, elementX + strlen(key) + 5, command);
	elementY++;
}

int drawKeybindingList(int y_offset) {
	elementY = y_offset;
	elementX = 0;
	iterate_keybindings(drawKeybindingElement);
	refresh(); // TODO Remove
	return elementY;
}

void finalizeUi() {
	endwin();
}
