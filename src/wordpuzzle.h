#ifndef _WORDPUZZLE_H
#define _WORDPUZZLE_H

#include <stdio.h>
#include "boolean.h"

#define ROW_SIZE 1000
#define COL_SIZE 1000

#define ROW(currlength) (currlength).rowEff
#define COL(currlength) (currlength).colEff
#define ELMT(currlength, i, j) (currlength).contents[(i)][(j)]
#define NEFF(L) (L).neff
#define ELMTL(L, i) (L).contents[(i)]

typedef char ElType;

typedef struct {
    ElType contents[ROW_SIZE][COL_SIZE];
    int rowEff;
    int colEff;
} Matrix;

typedef struct {
    ElType contents[50][50];
    int neff;
} List;

FILE* opentxtfile;
Matrix wordboard;
List wordsearched;

int counter;
int length;
char arr[50];
char reverse[50];
boolean found;
boolean currBool;

#endif