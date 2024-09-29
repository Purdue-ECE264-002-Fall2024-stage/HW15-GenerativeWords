# Generative Model of Words 1

Learning Goals
==============

In this assignment you will create and train a markov chain

You will learn to
* Understand the basics of Markov chains
    * Learn how a Markov chain model works in generating random text by associating words based on transitions between them
* Practice file I/O in C
* Manage memory dynamically by storing word transitions in a node-based structure

Markov chains
=============
A Markov chain is a sequence of events describing changes in state, with each state having fixed probabilities
of changing to each other state in every event.  For example, suppose a rabbit can either be asleep or awake
at any given hour.  If, each hour, if it is asleep, it has a 40% chance of waking the next hour, and a 60% of
remaining asleep; but if it is awake, it has a 30% chance of falling asleep the next hour, and a 70% chance of
remaining awake, then the rabbit's sleeping behavior can be modeled as a Markov chain.  There are two states:
asleep and awake, and the probabilities of transfer between states depend only on the current state.

Rabbits have unusual sleeping behaviors, and may nap during the day and be awake for times at night.  However,
if the rabbit were less likely to remain asleep after having been asleep for 6 hours than if it had just fallen
asleep, then a Markov chain could not model the behavior in the same way (it may have to consider different states
for the length of time the rabbit had been asleep or awake, for example).

In this assignment, you will train a Markov chain in which the states are various words that can be written,
based on those in some text.  Changing from one state to another is equivalent to writing one word after another.
The probability of changing from one word to another if those words do _not_ follow each other anywhere in the text
is zero.  For simplicity, the probabilities of changing from one word to any word that does follow in the text will
be equal, regardless of frequency (e.g., if the words "he was" occur 35 times, "he said" occur 22 times, and "he died" occur once, the chance of writing "was", "said", and "died" after writing "he" will still be considered equal).  This way, you only need to map out which transitions exist, not how often they occur.

What you need to do
===================

1. *Parse Input File:*
Write code to read the input file and extract words.
For the purpose of simplicity, a word will be defined as a whitespace-seperated set of characters. Punctuation would
stick to words or be its own word. Words with different capitalization will be treated differently. **New lines are ignored.**

2. *Build the Markov Chain:*
For each new, distinct word, create a structure (WordNode) that stores the word and the list of words that can follow it.
For each word that is not the first, add it to the previous word's WordNode's list of next words, if it doesn't
already appear.
**You must use the provided WordNode structure.** Look at the structure in generate.h.

3. *Manage statically-allocated memory:*
Note that you have a number of arrays made via the [] operator, with fixed lengths.  When putting entries in them, be sure to use a counter variable to keep track of how many entries you have, and not to add beyond the length.
**This will happen in at least one test case if you don't check the bounds.**  You can see the lengths of arrays in generate.h.

4. *Manage dynamically-allocated memory:*
You also have structures that are dynamically allocated.  Free this memory in the function ```free_word_list()``` in generate.c.  As you can (and should) see in main.c, this function will be called after main.c generates a text with the word list you made.

5. *Have fun:*
See what kind of funny imitations of texts your program can generate.  Think about ways this might be improved.  This step will not be graded.

***EXAMPLE***
As an example, consider a training based on the public domain<sup>[1](#myfootnote1)</sup> lyrics to "Happy Birthday":
> Happy birthday to you!
>
> Happy birthday to you!
>
> Happy birthday, dear ---!
>
> Happy birthday to you!

**Iterations**
- Training Iteration 1: Current word "Happy", add to word bank as a node, capital 'H' and all.
- Training Iteration 2: Current word "birthday", previous word is "Happy".  Add "birthday" to word bank as a node and to the list of words that can follow "Happy" in that node's list.
- Training Iteration 3: Current word "to", previous word is "birthday".  Add "to" to word bank as a node and to the list of words that can follow "birthday" in that node's list.
- Training Iteration 4: Current word "you!", previous word is "to".  Add "you!" to word bank, exclamation point and all, and add it to the list of words that can follow "to".
- Training Iteration 5: Current word "Happy", previous word is "you!".  As "Happy" already has a node in the word bank, do not add it, but do add that same node to the list of words that can follow "you!".
- Training Iteration 6: Current word "birthday", previous word is "Happy".  As "birthday" already has a node in the word bank, and that node was put in the list of words that can follow "Happy" in Training Iteration 2, no additions are needed.
- Training Iterations 7-9:  Current word and previous word same as in 3-5, so no additions are needed.
- Training Iteration 10:  Current word "birthday,", with a comma, previous word is "Happy".  As "birthday," with a comma is new for our simple program, add it to the word bank, and to the list of words that can follow "Happy".
- Training Iteration 11:  Current word "dear", previous word is "birthday,".  Add "dear" to word bank and to the list of words that can follow "birthday,".
- Training Iteration 12:  Current word "---!", that being a word to our simple program, previous word is "dear".  Add "---!" to word bank and to the list of words that can follow "dear".
- Training Iteration 13:  Current word "Happy", previous word is "---!".  As "Happy" is in the word bank, do not add it, but do add it to the list of words that can follow "---!".
- Training Iteration 14:  Current word "birthday", previous word is "Happy".  Same as iteration 7.
- Training Iterations 15-16:  Same as 8-9.

**Results**
The results of this, in the format in which they would be printed if lines 58-64 of main.c are uncommented (printing can be more useful for debugging when complex data structures make gdb prints harder to write), are:
```
Happy -> birthday birthday,
birthday -> to
to -> you!
you! -> Happy
birthday, -> dear
dear -> ---!
---! -> Happy
```

The resulting Markov chain has only one state that can lead to different states, "Happy", with the rest of the states forming loops ([birthday -> to -> you! -> Happy] and [birthday, -> dear -> --! -> Happy]), so the text generated from this would have no choice but to travel through those two loops, switching randomly (with even probability, in our program) after "Happy".  This imitates the simple song.  More complicated inputs, of course, will produce more complicated chains and more interesting outputs.

Test Your Program 𐐘⚔ඞ
=================
- Basic Functionality Test:
Several excerpts from texts have been provided in the textFiles dir. The makefile has been set up to test using those files: make test1-6 and make testall

- Memory Tests:
Use a memory checker tool (such as Valgrind) to ensure there are no memory leaks or improper memory access issues. Provided in makefile

- Try training the finished program on your own inputs as well! Single word predictions don't lead to very cohesive output but we will build upon this in the next assignment

Submission Instructions
=======================
Please submit generate.c only on Gradescope.

<a name="myfootnote1">1</a>: Rupa Marya v. Warner Chappell Music
