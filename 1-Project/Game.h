#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include "BSTY.h"
#include "LL.h"

using namespace std;

class Game {

    BSTY *dict; // the AVL tree
    LL *wordlist; // linked list of guesses
    int numletters; // the number of letters the user wants
    char *currletters; //the random set of letters
    int numright; // the count of the number of words in the AVL tree
    int totalwords; // the count of the total number of words generated LL wordlist; // the linked list of words the user typed in.

    public:
        /*constructor, initializes AVL tree from “dict.txt” by calling ReadTreeFromFile
        */
        Game();
        /* constructor, initializes AVL tree by calling ReadTreeFromFile with infile
        */
        Game(string infile);
        /* this is the user interface part – it asks how many letters the user wants, reads that number in, prints out the set of random letters (including at least one vowel, and then tells the user to start typing in words. Each word typed in is added to the wordlist (the linked list). When the user enters -1, the function then calculates the user’s total score by calling a function that first checks to make sure that each word only includes letters in the set of random letters and then checks to see if each word in the list is in the AVL tree. It then prints out the list of valid words and the user’s score. This function loops until the user no longer wants to play again.
        */
        void startGame();
        void readTreeFromFile (string dictfile); /* see below for this method*/
        /* this method (called by the startGame method) gets a set of x random letters and returns it.
        */
        char* getLetters(int x);
        /* this method (called by the startGame method) loops while the user enters potential words. Each word gets added to the linked list wordlist.
        */
        void getWords();
        /* checks to see of s only contains letters in currletters (the random set of letters) and returns true if s only contains valid letters, false otherwise
        */
        bool checkWLetters(string s);
        /* Goes through the list of words, checks to see if each word contains only letters in the random list (by calling checkWLetters), then checks to see if the valid words are in the avl tree and, if it is, increase the user’s score, and if it isn’t decreases the user’s score.
        */
        void checkWordsForScore();
};

#endif // GAME_H_INCLUDED
