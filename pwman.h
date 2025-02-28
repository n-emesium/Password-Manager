#ifndef PWMAN_H
#define PWMAN_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern char alph[27];
extern int dig[10];
extern char sym[];
void init(void);
int hashc(char *);
char *gpw(int);
int bins(char, int, int);
char *shiftc(char *, int);
char *decipher(char *, int);
void store(char *);

#endif

