#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1

struct entry_s {
	char *word;
	int count;
};

typedef struct entry_s entry_t;

int uniqueMorseRepresentations(char** words, int wordsSize) {
    char * code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int transform_count = 0;
    int i = 0;
    int j = 0;
    int num_words = wordsSize;
    char * curr_word;
    entry_t ** word_table = (entry_t **)malloc(sizeof(entry_t)*wordsSize);

    if (wordsSize == 0)
        return 0;
    
    // Initialize the word table
    for (i = 0 ; i < num_words ; i++) {
        word_table[i] = NULL;
    }

    char * new_morse_word;
    for (i = 0 ; i < num_words; i++) {
        curr_word = words[i];
        new_morse_word = (char *)malloc(sizeof(char)*strlen(curr_word)*4);
        memset(new_morse_word, '\0', sizeof(char)*strlen(curr_word)*4);
        for (j = 0 ; j < strlen(curr_word) ; j++) {
            new_morse_word = strcat(new_morse_word, code[curr_word[j] - 'a']);
            if (DEBUG) printf("--> %s\n", new_morse_word);
        }
        if (DEBUG) printf("word %s is morse_word %s\n", curr_word, new_morse_word);

        for (j = 0; j < num_words ; j++) {
            // Match
            if (word_table[j] != NULL && strcmp(word_table[j]->word, new_morse_word) == 0) {
                word_table[j]->count++;
                break;
            // No match or NULL       
            } else {
                // If NULL then we're at the end and can insert   
                if (word_table[j] == NULL) {
                    // Not found at this point
                    entry_t * new_entry = (entry_t *)malloc(sizeof(entry_t));
                    new_entry->word = new_morse_word;
                    new_entry->count = 1;
                    word_table[j] = new_entry;
                    break;
                }     
            }
        }
    }
    i = 0;
    while (word_table[i] != NULL) {
        if (DEBUG) printf("morse word %s has frequency %d\n", word_table[i]->word, word_table[i]->count);
        transform_count++;
        i++;
    }
    if (DEBUG) printf("transform count is %d\n", transform_count);
    return transform_count;    
}

int main(void) {

    char * examples[] = {};
    int wordsSize = 0;
    int rval = 0;
    rval = uniqueMorseRepresentations(examples, wordsSize);
    return 0;
}