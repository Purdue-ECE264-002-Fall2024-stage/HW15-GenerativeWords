#include <stdio.h>
#include <stdlib.h>
#include "generate.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <word count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read number of words to generate
    int wordCount = atoi(argv[2]);
    if (wordCount <= 0) {
        printf("Error: Invalid word count.\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Prepare data structure for storing word transitions
    WordNode *wordList[MAX_WORDS];
    int wordCountInFile = 0;

    // ඞ ඞ ඞ WILL NEED TO BE IMPLEMENTED ඞ ඞ ඞ
    train_markov(file, wordList, &wordCountInFile);

    fclose(file);
    generate_text(wordList, wordCountInFile, wordCount);
    free_word_list(wordList, wordCountInFile);

    return EXIT_SUCCESS;
}
