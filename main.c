#include <stdio.h>
#include <stdlib.h>
#include "generate.h"

// Functions used for generating random text, feel free to modify, not used in grading

static int get_random_index(int max) {
    return rand() % max;
}

void generate_text(WordNode *wordList[], int wordCount, int wordLimit) {
    if (wordCount == 0) {
        printf("Error: No input data.\n");
        return;
    }
    WordNode *current = wordList[get_random_index(wordCount)];
    printf("%s", current->word);
    for (int i = 1; i < wordLimit; i++) {
        if (current->nextWordCount == 0) {
            current = wordList[get_random_index(wordCount)];
            printf(" %s", current->word);
            continue;
        }
        current = current->nextWords[get_random_index(current->nextWordCount)];
        printf(" %s", current->word);
    }
    printf("\n");
}

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


    // Output the transitions. Uncomment for debugging.
    // for (int i = 0; i < wordCountInFile; i++) {
    //     printf("%s -> ", wordList[i]->word);
    //     for (int j = 0; j < wordList[i]->nextWordCount; j++) {
    //         printf("%s ", wordList[i]->nextWords[j]->word);
    //     }
    //     printf("\n");
    // }

    fclose(file);
    generate_text(wordList, wordCountInFile, wordCount);
    free_word_list(wordList, wordCountInFile);

    return EXIT_SUCCESS;
}
