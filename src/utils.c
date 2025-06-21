#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__linux__)
#include <stdio_ext.h>
#endif

void sysCommand(char *command) {
	#if defined(__linux__) || defined(__APPLE__)
		if (strcmp(command, "clear_terminal") == 0) {
			system("clear");
			return;
		}

		if (strcmp(command, "clear_stdin") == 0) {
			#if defined(__linux__)
				__fpurge(stdin);
			#elif defined(__APPLE__)
				fpurge(stdin);
			#endif
			return;
		}

		if (strcmp(command, "pause_terminal") == 0) {
			printf("Pressione qualquer tecla para continuar...");
			sysCommand("clear_stdin");
			int c = getchar();
			return;
		}
	#else
		if (strcmp(command, "clear_terminal") == 0) {
			system("cls");
			return;
		}

		if (strcmp(command, "clear_stdin") == 0) {
			fflush(stdin);
			return;
		}

		if (strcmp(command, "pause_terminal") == 0) {
			system("pause");
			return;
		}
	#endif
}

void normalizeString(char *string) {
    size_t len = strlen(string);
	
	if (len > 0 && string[len - 1] == '\n') {
	    string[len - 1] = '\0';
	}
}
