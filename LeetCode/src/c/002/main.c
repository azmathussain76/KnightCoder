#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Leetcode #2: Add Two Numbers
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define DEBUG 1

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


void printNumber(ListNode * nodenum) {
    int i = 0;
    while (nodenum != NULL && i < 10) {
        printf("%d->", nodenum->val);
        fflush(stdout);
        nodenum = nodenum->next;
        i++;
    }
    printf("NULL\n");
    fflush(stdout);
    return;
}

struct ListNode* buildNumber(long int number) {
    ListNode * head;
    ListNode * current;
    ListNode * prev;

    head = current;

    head = (ListNode *)malloc(sizeof(ListNode));
    int digit = number % 10;
    head->val = digit;
    head->next = NULL;

    number = number / 10;

    if (number > 0) {
        current = prev = head;
        head->next = current;
        prev->next = current;
    }

    while (number > 0) {
        current = (ListNode *)malloc(sizeof(ListNode));
        digit = number % 10;
        current->val = digit;
        current->next = NULL;
        prev->next = current;

        // handle next steps
        number = number / 10;
        current = current->next;
        prev = prev->next;
    }
    return head;
}


struct ListNode* appendDigitToNumber(int digit, ListNode* digit_list) {
    ListNode * head = digit_list;
    ListNode * current;

    while (digit_list->next != NULL) {
        digit_list = digit_list->next;
    }

    // Now add the new space
    current = (ListNode *)malloc(sizeof(ListNode));
    current->val = digit;
    current->next = NULL;

    digit_list->next = current;

    return head;
}


struct ListNode* addTwoNumbers_old(struct ListNode* l1, struct ListNode* l2) {
    /*
    Traverse both lists for each digit place, at each node extract the digit
    there and add it to an accumulator.
    For every advance in digit ("dig_place"), keep track of that and multiply the subtotal by 10^dig_place
    to shift the result value into the right alignment.
    Run this as two back-to-back while loops to keep the run time at O(n)
    */
    ListNode * result;
    long int accum = 0;
    int dig_place = 0;
    int carry_bit = 0;
    int dig_accum = 0;
    
    while (l1 != NULL) {
    }
    if (DEBUG)
        printf("Accum result is %d\n", accum);

    dig_place = 0;
    while (l2 != NULL) {
        accum += l2->val*pow(10,dig_place);
        dig_place++;
        l2 = l2->next;
    }
    if (DEBUG)
        printf("Accum result is %d\n", accum);
    result = buildNumber(accum);
    return result;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /*
    Traverse both lists for each digit place, at each node extract the digit
    there and add it to an accumulator.
    For every advance in digit ("dig_place"), keep track of that and multiply the subtotal by 10^dig_place
    to shift the result value into the right alignment.
    Run this as two back-to-back while loops to keep the run time at O(n)
    */
    ListNode * result = NULL;

    long int accum = 0;
    int carry_bit = 0;
    int dig_accum = 0;

    while (l1 != NULL || l2 != NULL) {
        if (carry_bit) {
            dig_accum += 1;
            carry_bit = 0;
        }

        if (l1 != NULL) {
            dig_accum += l1->val;
            l1 = l1->next;
        }
        if (DEBUG)
            printf("Dig Accum result(l1) is %d\n", dig_accum);

        if (l2 != NULL) {
            dig_accum += l2->val;
            l2 = l2->next;   
        }
        if (DEBUG)
            printf("Dig Accum result(l2) is %d\n", dig_accum);

        if (dig_accum / 10 > 0) {
            carry_bit = 1;
            dig_accum = dig_accum % 10;
        }
        if (DEBUG)
            printf("Dig Accum result is %d\n", dig_accum);

        if (DEBUG && carry_bit)
            printf("Carry is active! %d\n", carry_bit);

        if (result == NULL) {
            result = buildNumber(dig_accum);
        } else {
            result = appendDigitToNumber(dig_accum, result);
        }
        dig_accum = 0;
    }

    printNumber(result);
    if (DEBUG && carry_bit)
        printf("Carry is active yall! %d\n", carry_bit);

    if (carry_bit == 1) {
        result = appendDigitToNumber(carry_bit, result);
    }

    return result;
}


int main(void) {
    ListNode * sum;
    ListNode * num1 = buildNumber(9);
    //ListNode * num1 = buildNumber(342);

    // [1,9,9,9,9,9,9,9,9,9]
    ListNode * num2 = buildNumber(9999999991);
    //ListNode * num2 = buildNumber(465);

    if (DEBUG) {
        printNumber(num1);
        printNumber(num2);
    }
    sum = addTwoNumbers(num1, num2);

    if (DEBUG)
        printNumber(sum);
    return 0;
}