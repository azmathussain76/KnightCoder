#include <stdio.h>
#include <string.h>

# define I 1
# define V 5
# define X 10
# define L 50
# define C 100
# define D 500
# define M 1000

int romanToInt(char* s) {
    int len = strlen(s);
    
    int last = 0;
    
    int int_accum = 0;
    
    // I can be placed before V (5) and X (10) to make 4 and 9. 
    // X can be placed before L (50) and C (100) to make 40 and 90. 
    // C can be placed before D (500) and M (1000) to make 400 and 900.
    
    for (int i = len-1 ; i >= 0 ; i--) {
        int sign = 1;
        switch (s[i]) {
            case 'I':
                if (last == 'V' || last == 'X') {
                    sign = -1;
                }
                int_accum += I*sign;
                sign = 1;
                break;
                
            case 'V':
                int_accum += V;
                break;
                
            case 'X':
                if (last == 'L' || last == 'C') {
                    sign = -1;
                }
                int_accum += X*sign;
                sign = 1;
                break;
                    
            case 'L':
                int_accum += L;
                break;
                
            case 'C':
                if (last == 'D' || last == 'M') {
                    sign = -1;
                }
                int_accum += C*sign;
                sign = 1;
                break;
                
            case 'D':
                int_accum += D;
                break;
                
            case 'M':
                int_accum += M;
                break;
                
            default:
                int_accum += 0;
        }
        last = s[i];        
    }
    
    return int_accum;
}

int main(void) {
    char s[] = "MCMXCIV";
    int value;
    value = romanToInt(s);

    printf("answer is %d\n", value);
    return 0;
}