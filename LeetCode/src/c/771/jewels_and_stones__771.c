#include <string.h>

int numJewelsInStones(char* J, char* S) {
    int j_len;
    int s_len;

    int matches = 0;

    j_len = strlen(J);
    s_len = strlen(S);

    for (int i = 0; i < j_len; i++) {
        for (int j = 0; j < s_len; j++) {
            if (J[i] == S[j]) {
                matches++;
            }
        }
    }
    return matches;
}

int main (void){
    char * j = "aA";
    char * s = "aAAbbbb";

    int rval;
    rval = numJewelsInStones(j, s);
    printf("Result is %d\n", rval);
    return 0;
}
