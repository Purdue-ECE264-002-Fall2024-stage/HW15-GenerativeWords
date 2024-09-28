# Generative Model of Words 1

Learning Goals
==============

In this assignment you will create and train a markov chain

You will learn to
* Understand the basics of Markov chains
    * Learn how a Markov chain model works in generating random text by associating words based on transitions between them
* Practice file I/O in C
* Manage memory dynamically by storing word transitions in a node based structure

What you need to do
===================

1. *Parse Input File:*
Write code to read the input file and extract words.
As you read the words, link each word to the words that follow it in the text. Store these links in a dynamic data structure.
For the purpose of simplicity, a word will be defined as a whitespace-seperated set of characters. Punctuation would
stick to words or be its own word. Words with different capitalization will be treated differently.

2. *Build the Markov Chain:*
For each word, create a structure (WordNode) that stores the word and the list of words that can follow it.
When a word is repeated, **ensure it updates the list of potential next words rather than duplicating entries.**
**You must use the provided WordNode structure**

3. *Free the used memory:*
Implement free_word_list to free the data structure used

***EXAMPLE***
- **Example String for training: "Do or do not or try -- or don't"**
- Training Iteration 1: Current word "Do", no previous word so just add to wordbank as a node
- Training Iteration 2: Current word "or", previous word is "Do" so add "or" to nextList of "Do" and add "or" to wordbank
- Training Iteration 3: Current word "do", previous word is "or" so add "do" to nextList of "or" and add "do" to wordbank
- Training Iteration 4: Current word "not", previous word is "do" so add "not" to nextList of "do" and add "not" to wordbank
- Training Iteration 6: Current word "or", previous word is "not" so add "or" to nextList of "not" but don't add "or" to wordBank because it already exists
- Training Iteration 7: Current word "try", previous word is "or" so add "try" to nextList of "or" and add "try" to wordbank
- Training Iteration 8: Current word "--", previous word is "try" so add "--" to nextList of "try" and add "--" to wordbank
- Training Iteration 9: Current word "or", previous word is "--" so add "or" to nextList of "--" but don't add "or" to wordBank because it already exists
- Training Iteration 10: Current word "don't", previous word is "or" so add "don't" to nextList of "or" and add "don't" to wordbank
- **When finished, you should have a data structure that represents all the possible transistions from each word to other words**



Test Your Program 𐐘⚔ඞ
=================
- Basic Functionality Test:
Several excerpts from texts have been provided in the textFiles dir. The makefile has been set up to test using those files: make test1-6 and make testall

- Memory Tests:
Use a memory checker tool (such as Valgrind) to ensure there are no memory leaks or improper memory access issues. Provided in makefile

- Try training the finished program on your own inputs as well! Single word predictions don't lead to very cohesive output but we will build upon this in the next assignment

Submission Instructions
=======================
Please just submit generate.c on gradescope
