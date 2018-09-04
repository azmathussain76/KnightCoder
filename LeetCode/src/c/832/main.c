#include <stdio.h>
#include <stdlib.h>

/* 

Leetcode 832. Flipping an Image

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

void print_array(int ** A, int r, int c) {
    int i,j;

    printf("rowsize=%d, colsize=%d\n", r,c);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("A[%d][%d]=%d\t", i , j, *((A+i*c) + j));
            fflush(stdout);
        }
        printf("\n");
    }
            
    return;
}

int* invert_array(int * a) {
    int i = 0;
    int a_bounds = sizeof(a)/sizeof(int);

    int * a_return;
    a_return = (int *)malloc(sizeof(int)*a_bounds);

    for (i = 0; i < a_bounds ; i++) {
        a_return[i] = (int)(a[i] ^ 1);
    }
    return a_return;
}

int* reverse_array(int * a) {
    int i = 0;
    int a_bounds = sizeof(a)/sizeof(int);

    int * a_return;
    a_return = (int *)malloc(sizeof(int)*a_bounds);

    for (i = 0 ; i < a_bounds; i++) {
        a_return[i] = a[a_bounds - i];
    }
    return a_return;
} 

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int r = ARowSize, c = *AColSizes;
    int i = 0, j = 0;
    int ** ret_A;

    columnSizes = (int **)malloc(c * sizeof(int *));

    ret_A = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++) {
         ret_A[i] = (int *)malloc(c * sizeof(int));
    }

    for (i = 0 ; i < ARowSize ; i ++) {
        ret_A[i] = invert_array(reverse_array(A[i]));
        printf(" %d ", ret_A[i]);
    }
    return ret_A;
}

int main(void) {
    int r,c;
    int A[3][3] = { { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 } };
    int A_rowsize;
    int *  A_colsize;
    int *  A_returnsize;
    int ** columnSizes;

    int **B;

    r = (int)(sizeof(A[0])/sizeof(int));
    c = (int)(sizeof(A)/sizeof(A[0]));

    A_rowsize = r;
    A_colsize = &c;

    print_array((int **)A, r, c);
    B = flipAndInvertImage((int**)A, A_rowsize, A_colsize, (int**)A_colsize, A_returnsize);
    return 0;
}