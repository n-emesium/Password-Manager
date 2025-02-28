#include "pwman.h"
#include <unistd.h>
#define DEFAULT 10
int matoi(char *c) {
	int n = 0;
	for (int i = 0; *(c + i) != '\0'; i++) {
		n = 10 * n + (*(c + i) - '0');
	}
	return n;
}

int main(int argc, char *argv[]) {
	init();
	for (int i = 0; i < matoi(argv[1]); i++) {
		//store(gpw(DEFAULT));
		char *c = gpw(DEFAULT);		
		store(c);
		free(c);
	}
	system("cat passwords.txt");
	return 0;
}
