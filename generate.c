#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate.h"

// You will need to implement the following 2 functions

void train_markox(FILE *file, WordNode *wordList[], int *wordCount) {
    
}

void free_word_list(WordNode *wordList[], int wordCount) {
    
}

// Below functions are used for generating output. Don't modify them.

static int get_random_index(int max) {
    return rand() % max;
}

void generate_text(WordNode *wordList[], int wordCount, int wordLimit) {
    WordNode *current = wordList[get_random_index(wordCount)];
    printf("%s", current->word);
    for (int i = 1; i < wordLimit; i++) {
        if (current->nextWordCount == 0) current = wordList[get_random_index(wordCount)]; // reaches endpoint of transistions, find new random beginning
        current = current->nextWords[get_random_index(current->nextWordCount)];
        printf(" %s", current->word);
    }
    printf("\n");
}

