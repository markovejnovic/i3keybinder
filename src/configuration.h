#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "keybindings.h"
#include <linux/limits.h>

#define CONFIGURATION_LOCATION_USER "/.config/i3/config"

#define I3_BINDSYM "bindsym"
#define I3_COMMENT "#"

#define REGEX_I3_BINDSYM_PATTERN "^" I3_BINDSYM "\\s([^ ]+)\\s(.+)$"

static char *configurationPath;

/**
 * Automatically searches for the configuration path
 *
 * It checks to see if the following files exist and returns the first one in 
 * the following list
 * 	1. ~/.config/i3/config
 *
 * Sets configurationPath to whatever it tries to find to be the path of 
 * the configuration file. If it cannot find a valid configuration path 
 * returns -1.
 *
 * Returns:
 * 	-1 - If unable to find a suitable i3 configuration file
 * 	0 - If able to find a suitable i3 configuration file.
 */
int getConfigurationPath();

/**
 * Reads the i3 keybind configuration and automatically stores it in the 
 * keybindings.h->keybindings hashtable. The configurationPath is the one 
 * found in this file.
 *
 * Returns:
 * 	Integer - Number of keybindings read
 * 	-1 - If an error has occurred.
 */
int readConfiguration();

#endif
