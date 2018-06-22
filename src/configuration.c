#include "configuration.h"
#include <linux/limits.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "keybindings.h"
#include <stdlib.h>

int getConfigurationPath(char *path) {
	char location[PATH_MAX];
	strcpy(location, getenv("HOME"));
	strcat(location, CONFIGURATION_LOCATION_USER);
	if (access(location, R_OK | W_OK) == 0) {
		configurationPath = location;
		return 0;
	}

	return -1;
}

/**
 * TODO Make this a bit safer for malformed i3 configuration files
 */
int readConfiguration() {
	int i = 0;
	FILE *fp;
	if ((fp = fopen(configurationPath, "r")) == NULL)
		return -1;

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (strstr(line, I3_BINDSYM) != NULL &&
			strstr(line, I3_COMMENT) == NULL) {
			char *key, *command;

			// So basically i3 configuration looks something like
			// 'bindsym $mod+3 exec --no-startup-id someexecutable'
			// which means that in order to get the key and the command we need to
			// split the string at the first space, but before that we have to 
			// get rid of that annoying bindsym.
			char *start = strstr(line, I3_BINDSYM " ");
			char *end = start + strlen(I3_BINDSYM " ");
			memmove(start, start + strlen(I3_BINDSYM " "), strlen(end) + 1);
			command = strchr(line, ' ') + 1;
			*(command - 1) = 0;
			key = line;
			add_keybinding(key, command);
		}
	}

	fclose(fp);
	if (line)
		free(line);
}
