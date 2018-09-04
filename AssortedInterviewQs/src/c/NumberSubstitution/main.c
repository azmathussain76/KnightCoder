#include <stdio.h>
#include <stdint.h>

int func(uint32_t number, int start, int end, int val) {
    // start = 1
    // end = 3
    int start_mask = 1 << start;
    start_mask = ~(start_mask - 1);
    int end_mask = 1 << end+1;
    end_mask = ~(end_mask - 1);

    int combo_mask = end_mask & start_mask;
    printf("mask=%x,sm=%x,em=%x\n", combo_mask, start_mask, end_mask);

    number = number & combo_mask;
    
    number = number | (val << start);
    
    return number;
}

int main(void) {
  uint32_t result1 = func(201, 2, 6, 7);

  printf("Result #1 is: %d (%x, %x)\n", result1, 201, 7);
  printf("Hello World\n");
  return 0;
}