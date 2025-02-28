#include "pwman.h"

char alph[27];
int dig[10];
char sym[] = {'!', '^', '+', '%', '&', '/', '(', ')', '=', '?', '-', '_', ',', ';', '.', ':', '<', '>'};	    

void init(void) {
	srand(time(NULL));
	for (int i = 0; i < 26; i++) {
		alph[i] = (int)('a' + i);		
	}
	alph[26] = '\0';
	for (int i = 0; i <= 9; i++) {
		dig[i] = i;
	}
}

int hashc(char *c) { //hashes a basic key
	int res = 0;
	int len = 0;
	for (int i = 0; *(c + i) != '\0'; i++) {
		res += *(c + i);
		len++;
	}
	return res % (c[0] + c[len]);
}

char *gpw(int n) {
	char *res = malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++) {
		int sset = rand() % 3;
		switch (sset) {
			case 0: //alph
				res[i] = alph[rand() % 26];
				break;
			case 1: //dig
				res[i] = '0' + dig[rand() % 10];
				break;
			case 2: //sym
				res[i] = sym[rand() % (sizeof(sym) / sizeof(char))];
				break;
		}
	}
	res[n] = '\0';
	return res;
}

int bins(char c, int l, int r) {
	if (l <= r) {
		int mid = (r + l) / 2;
		if (alph[mid] == c) {
			return mid;
		} else if (alph[mid] > c) {
			return bins(c, l, mid - 1);
		} else {
			return bins(c, mid + 1, r);
		}
	}
	return -1;
}

char *shiftc(char *c, int sh) {
	char *max_buffer = malloc(256 * sizeof(char));
	int sz = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		max_buffer[i] = alph[(bins(c[i], 0, 25) + sh) % 26];
		sz++;
	}
	max_buffer[sz] = '\0';
	max_buffer = realloc(max_buffer, (sz + 1) * sizeof(char));
	return max_buffer;
}

char *decipher(char *c, int sh) {
	return shiftc(c, -1 * sh);
}

void store(char *c) {
	FILE *f = fopen("passwords.txt", "a");
	fprintf(f, "%s\n", c);
	fclose(f);
}
