/*
hw5: Write a program to scan 2d character array & 
     a 1d character array from user,
     find whether 1d array is part of 2d character array or not
*/
#include<stdio.h>

int main() {
    int i, j, k;
    int _2drow, _2dcol, _1dcol, match_count;

    printf("Enter row size of 2D array: ");
    scanf("%d", &_2drow);

    printf("Enter col size of 2D array: ");
    scanf("%d", &_2dcol);

    char _2d[_2drow][_2dcol];

    printf("The 1D array has 1 row only.\n");

    do {
        printf("Enter col size of 1D array (<= %d): ", _2dcol);
        scanf("%d", &_1dcol);
    } while (_1dcol > _2dcol);

    printf("Enter 2D array strings (%d rows):\n", _2drow);
    for(i = 0; i < _2drow; i++) {
        scanf("%s", _2d[i]);
    }

    char _1d[1][_1dcol];

    printf("Enter the 1D array string (%d chars):\n", _1dcol);
    scanf("%s", _1d[0]);

    for(i = 0; i < _2drow; i++) {
        for(j = 0; j <= _2dcol - _1dcol; j++) {
            
            match_count = 0;

            for(k = 0; k < _1dcol; k++) {
                if(_2d[i][j+k] != _1d[0][k])
                    break;
                match_count++;
            }

            if(match_count == _1dcol)
                printf("Match found at [%d][%d]\n", i, j);
        }
    }

    return 0;
}
