#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDLEN 100
#define DEBUG 0

// ["flower","flow","flight"]
// ["flower",
//  "flow",
//  "flight"]

char* appendChar(char* str, char letter) {
    if (DEBUG)
        printf("str is %s\n", str);
    int len = strlen(str);
    /* one for extra char, one for trailing zero */
    char *str2 = malloc(len + 1 + 1 ); 
    strcpy(str2, str);
    str2[len] = letter;
    str2[len + 1] = '\0';
    if (DEBUG)
        printf("str is now %s\n", str);
    free( str );
    return str2;   
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char * output;
    output = (char *)malloc((MAXWORDLEN+1)*sizeof(char));
    output = memset(output, '\0', (MAXWORDLEN+1)*sizeof(char));
    
    int result = 0;
    // Iterate for each word
    for (int col_idx = 0 ; col_idx < MAXWORDLEN ; col_idx++) {
        if (DEBUG)
            printf("col is %d\n", col_idx);

        char letter; 
        for (int row_idx = 0; row_idx < strsSize ; row_idx++) {
            if (DEBUG)
                printf("row is %d\n", row_idx);
            letter = strs[row_idx][col_idx];
            result = result ^ (int)letter;
        }
        if (DEBUG) {
            printf("result is %d, letter is %c\n", result, letter);
            fflush(stdout);
        }
        if (result == letter || result == 0) {
            // append the output word
            output = appendChar(output, letter);
        } else {
            return output;
        }  
        if (DEBUG)
            printf("done here!\n"); 
        fflush(stdout);                 
        result = 0;
    }
    return output;
}
int main(void) {
    char * prefix;
    //char * str[4] = {"flower","flow","flight","flux"};
    //char * str[3] = {"dog","racecar","car"};
    char * str[3] = {"neato", "near", "neal"};
    prefix = longestCommonPrefix(str, 3);
    printf("Longest prefix is %s\n", prefix);
    return 0;
}