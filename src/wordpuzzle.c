#include "boolean.h"
#include "wordpuzzle.h"
#include "time.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile() {
    printf("Masukkan nama file puzzle word search: ");
    char wordpuzzlefile[50];
    gets(wordpuzzlefile);

    opentxtfile = fopen(wordpuzzlefile, "r");

    char tokenMap = fgetc(opentxtfile);
    char beforeToken = tokenMap;
    ROW(wordboard) = 0; COL(wordboard) = 0;
    int rows = 0; int cols = 0;
    while (tokenMap != '\n' || beforeToken != '\n') {
        if (tokenMap == '\n') {
            ROW(wordboard)++;
            rows++;
            COL(wordboard) = cols;
            cols = 0; 
        }
        if (tokenMap != ' ' && tokenMap != '\n') {
            ELMT(wordboard, rows, cols) = tokenMap;
            cols++;
        }
        beforeToken = tokenMap;
        tokenMap = fgetc(opentxtfile);
    }

    NEFF(wordsearched) = 0;
    char line[100];
    while (fgets(line, sizeof(line), opentxtfile)) {
        strcpy(ELMTL(wordsearched, NEFF(wordsearched)), line);
        NEFF(wordsearched)++;
    }

    for (int i = 0; i < NEFF(wordsearched)-1; i++) {
        ELMTL(wordsearched, i)[strlen(ELMTL(wordsearched, i))-1] = '\0';
    }

    fclose(opentxtfile);
    counter = 0;
}

boolean isFoundEast(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i,j+currlength)==ELMTL(wordsearched,n)[currlength])){
                currlength++;
                counter++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y == i && z >= j && z <= j + wordlength - 1){
                            printf("%c ",(ELMT(wordboard, y, z)));
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundSoutheast(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    int counterwordlength = wordlength;
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i+currlength,j+currlength)==ELMTL(wordsearched,n)[currlength])){
                currlength++;
                counter++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y >= i && y == i + wordlength - counterwordlength && z >= j && z == j + wordlength - counterwordlength && counterwordlength > 0){
                            printf("%c ",(ELMT(wordboard, y, z)));
                            counterwordlength--;
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundSouth(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i+currlength,j)==ELMTL(wordsearched,n)[currlength])){
                currlength++;
                counter++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y >= i && y <= i + wordlength - 1 && z == j){
                            printf("%c ",(ELMT(wordboard, y, z)));
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundSouthwest(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    int counterwordlength = wordlength;
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i+currlength,j-currlength)==ELMTL(wordsearched,n)[currlength])){
                counter++;
                currlength++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y >= i && y == i + wordlength - counterwordlength && z <= j && z == j - wordlength + counterwordlength && counterwordlength > 0){
                            printf("%c ",(ELMT(wordboard, y, z)));
                            counterwordlength--;
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundWest(int n){
    /* n adalah urutan kata ke berapa yang ingin di cari */
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i,j-currlength)==ELMTL(wordsearched,n)[currlength])){
                counter++;
                currlength++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y == i && j - wordlength + 1 <= z && z <= j){
                            printf("%c ",(ELMT(wordboard, y, z)));
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundNorthwest(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    int counterwordlength = wordlength;
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i-currlength,j-currlength)==ELMTL(wordsearched,n)[currlength])){
                counter++;
                currlength++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y >= i - wordlength + 1 && y == i + 1 - counterwordlength && z >= j - wordlength + 1 && z == j - counterwordlength + 1 && counterwordlength > 0){
                            printf("%c ",(ELMT(wordboard, y, z)));
                            counterwordlength--;
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundNorth(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i-currlength,j)==ELMTL(wordsearched,n)[currlength])){
                counter++;
                currlength++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (i - wordlength + 1 <= y && y <= i && z == j){
                            printf("%c ",(ELMT(wordboard, y, z)));
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean isFoundNortheast(int n){
    boolean found = false;
    int wordlength = strlen(ELMTL(wordsearched,n));
    int counterwordlength = wordlength;
    for (int i = 0; i < ROW(wordboard); i ++){
        for (int j = 0; j< COL(wordboard); j++){
            int currlength = 0;
            while ((currlength<wordlength)&&(ELMT(wordboard,i-currlength,j+currlength)==ELMTL(wordsearched,n)[currlength])){
                counter++; currlength++;
            }
            if (currlength==wordlength){
                for (int y = 0; y <ROW(wordboard); y++){
                    for (int z = 0; z<COL(wordboard); z++){
                        if (y >= i - wordlength + 1 && y == i + 1 - counterwordlength && z <= j + wordlength - 1 && z == j - 1 + counterwordlength && counterwordlength > 0){
                            printf("%c ",(ELMT(wordboard, y, z)));
                            counterwordlength--;
                        }
                        else {
                            printf(". ",(ELMT(wordboard, y, z)));
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

int main(){
    readFile();
    printf("\n");
    printf("----- W O R D  P U Z Z L E ----- \n");
    for (int i = 0; i <ROW(wordboard); i++){
        for (int j = 0; j<COL(wordboard); j++){
            printf("%c ",(ELMT(wordboard, i, j)));
        }
        printf("\n");
    }
    printf("\n------ K E Y  W O R D -----\n");
    for (int i = 0; i <= NEFF(wordsearched); i++){
        printf("%s\n", ELMTL(wordsearched, i));
    }
    clock_t initiatepuzzle = clock();
    for (int n = 0; n < NEFF(wordsearched); n++){
        isFoundEast(n);
        isFoundSoutheast(n);
        isFoundSouth(n);
        isFoundSouthwest(n);
        isFoundWest(n);
        isFoundNorthwest(n);
        isFoundNorth(n);
        isFoundNortheast(n);
    }
    clock_t terminatepuzzle = clock();
    double duration = ((double) (terminatepuzzle - initiatepuzzle))/(1000);

    printf("Durasi eksekusi program adalah sebesar : %.3f sekon\n", (float)duration);
    printf("Jumlah perbandingan huruf adalah sebanyak : %d kali", counter);
}