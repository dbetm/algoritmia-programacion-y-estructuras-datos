#include "header.h"

int valida() {
    int num, ok, ch;
    do {
		fflush(stdout);
		if ((ok = scanf("%d", &num)) == EOF)
		return EXIT_FAILURE;

		if ((ch = getchar()) != '\n') {
    		ok = 0;
    		printf("Vuelva a intentarlo: ");
    		while ((ch = getchar()) != EOF && ch != '\n');
		}
	} while (!ok);

	return num;
}
