#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate.h"

// You will need to implement the following 2 functions

// The Markov training function develops a list of all the valid word transitions
// found in the input file.

// As seen in main.c, FILE * file is the immediate result of opening the file 
// (i.e., a pointer to the beginning of the file)
// The command to close the file is already written in main.c, so you don't need it here.

// WordNode *wordList[] is an array of pointers of length MAX_WORDS.  It holds a bank
// of WordNodes, of which you should have one for each distinct word.  Review the structure
// of WordNode in generate.h, and note where to use dynamic allocation.
// You may have used an array of pointers in HW4 or other assignments.

// int *wordCount points to an integer that should contain the number of words
// in the word bank (i.e., the number of pointers in wordList that have been
// initialized to point to existing WordNodes)
void train_markov(FILE *file, WordNode *wordList[], int *wordCount) {
    
}

// The second function, given the word list you used in the previous 
// function and the final value of word count,
// frees all dynamically allocated memory.
void free_word_list(WordNode *wordList[], int wordCount) {
    
}

