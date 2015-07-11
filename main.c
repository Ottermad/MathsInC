#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "maths.h"

int main(int argc, char *argv[])
{
	// Loop through arguments
	int i = 0;
	for (i = 1; i < argc; i++) {
		char *option = argv[i];

		if (strcmp(option, "pyth") == 0) {
			pythagorasTheoremInput();
		} 
		else if (strcmp(option, "nth") == 0) {
			nthTermInput();
		}
		else if (strcmp(option, "share") == 0) {
			shareRatioInput();
		}
		else {
			printf("Not a valid option\n");
		}
	}
	return 0;
}