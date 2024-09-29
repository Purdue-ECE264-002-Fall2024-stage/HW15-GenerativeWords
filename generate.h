#ifndef GENERATE_H
#define GENERATE_H

#include <stdio.h>

// These values may be changed for testing
#define MAX_WORDS 10000
#define MAX_NEXT_WORDS 100
#define MAX_WORD_LENGTH 50

/** 
* @brief Structure to represent each word and its possible transitions
*/
typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    struct WordNode *nextWords[MAX_NEXT_WORDS];
    int nextWordCount;
} WordNode;

/**
 * @brief Function (NOT GIVEN) to train the Markov chain by reading words from the file. 
 * THIS FUNCTION STILL NEEDS TO BE IMPLEMENTED.
 * 
 * @param file - The input file containing text to train on.
 * @param wordList - An array of pointers to WordNode, representing the word transitions.
 * @param wordCount - Pointer to an integer that stores the number of words in wordList.
 * 
 * 
 */
void train_markov(FILE *file, WordNode *wordList[], int *wordCount);

/**
 * @brief Function to free dynamically allocated memory for the word list.
 * 
 * @param wordList - An array of pointers to WordNode, representing the word transitions.
 * @param wordCount - The number of words in wordList.
 */
void free_word_list(WordNode *wordList[], int wordCount);

#endif
