#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "ui.h"
#include "keybindings.h"
#include "configuration.h"

void gracefulExit(int signo) {
	finalizeUi();
	exit(0);
}

int main(int argc, char *argv[]) {
	// Connect signals
	signal(SIGINT, gracefulExit);

	initUi();
	int yOffset = drawHeader();
	if (getConfigurationPath() == 0) {
		readConfiguration();
	} else {
		return -1;
	}
	drawKeybindingList(yOffset);

	while (1) {
		// Main event loop
		sleep(1);
	}

	return 0;
}
