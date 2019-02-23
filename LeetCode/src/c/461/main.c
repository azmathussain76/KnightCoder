#include <stdio.h>

/*

Leetcode 461

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

#define SIZEOF_INT_IN_BITS 32

int hammingDistance(int x, int y) {
    int i;
    int count = 0;
    for (i = 0 ; i < SIZEOF_INT_IN_BITS ; i++) {
        if ((x ^ y) & 1) {
            count++;
        }
        x = x >> 1;
        y = y >> 1;
    }

    return count;
}

int main(void) {
    int result = 0;
    int x = 1, y = 4;
    result = hammingDistance(x,y);
    printf("Hamming distance is %d\n", result);
    return 0;
}