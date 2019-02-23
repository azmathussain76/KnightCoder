#include <stdio.h>
#include <stdlib.h>

/*

Leetcode 728: Self Dividing Numbers

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

#define MAX_DIGITS 5

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int * return_array = (int *)malloc(sizeof(int)*10000);
    int c = -1;
    int * digarray = (int *)malloc(sizeof(int)*(MAX_DIGITS-1));
    *returnSize = 0;
    int * curr_number = return_array;

    for (c = left ; c <= right ; c++) {
        if (c % 10 == 0) {
            continue;
        }
        int num = c;
        int i = 0;
        int digits = 0;
        int digit;
        do {
            digit = num % 10;
            digarray[i++] = digit;
            digits++;
            num = num / 10;
        } while (num > 0);

        fflush(stdout);

        int condition = 1;
        for (i = 0 ; i < digits ; i++) {
            if (digarray[i] != 0 && (c % digarray[i]) > 0) {
                condition = 0;
                break;
            } else {
                if (!digarray[i]) {
                    condition = 0;
                    break;
                }
            }
        }  
        fflush(stdout);

        if (condition) {
            fflush(stdout);
            curr_number[0] = c;
            curr_number++;
            fflush(stdout);
            *returnSize = *returnSize + 1;
        } 

    }
    return return_array;
}

int main(void) {
    int l = 1;
    int r = 22;
    int rsize;

    int * sdiv_list;

    sdiv_list = selfDividingNumbers(l, r, &rsize);

    printf("[");
    for (int i = 0 ; i < rsize ; i++) {
        printf("%d, ", sdiv_list[i]);
    }
    printf("]\n");
    fflush(stdout);

    return 0;
}