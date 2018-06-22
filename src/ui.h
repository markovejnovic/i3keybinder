#ifndef UI_H
#define UI_H

#include <curses.h>

typedef struct {
	WINDOW window;
	int x0;
	int y0;
	int w;
	int h;
} WindowProperties;

/**
 * Initializes the UI properties
 */
void initUi();

/**
 * Draws the UI header of the application inside the main window
 *
 * Returns:
 *	int - The Y coordinate of the next empty line
 */
int drawHeader();

/**
 * Draws the list of the keybindings
 *
 * Arguments:
 *	y_offset - The Y coordinate of the cursor at which the drawing should start
 *
 * Returns:
 *	int - The Y coordinate of the next empty line
 */
int drawKeybindingList(int y_offset);

/**
 * Finalizes the UI session
 */
void finalizeUi();

#endif
