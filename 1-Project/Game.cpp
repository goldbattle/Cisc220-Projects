#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <time.h>
#include "Game.h"
#include "BSTY.h"

using namespace std;

Game::Game() {
    // Call sub-construtor
    Game("dict.txt");
}

Game::Game(string infile) {
    // Random time seed
    srand(time(NULL));
    // Init tree
    dict = new BSTY();
    // Init linked list
    wordlist = new LL();
    // Read in the dictionary
    readTreeFromFile(infile);
    // Start the game
    startGame();
}


void Game::startGame() {
    bool is_end = false;
    // Loop till user enters "no"
    while(!is_end) {
        // Ask the user how many letters
        int c_letters;
        cout << "How many letters do you want to play with?" << endl;
        cin >> c_letters;
        // Clear the input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Make sure we are positive and not 0
        if(c_letters <= 0) {
            cout << "Please enter a positive number.\n" << endl;
            continue;
        }
        // Get random set of letters
        currletters = getLetters(c_letters);
        // Call getWords(), get words from the user
        getWords();
        // Call checkWordsForScore(), calc the user's score

        // Print score
        cout << "================\n    Score:\n================" << endl;
        cout << "Number right: " << numright << endl;
        cout << "Total guesses: " << totalwords << endl;
        // Ask if they want to play again
        string response;
        cout << "Do you want to play again? (yes/no)" << endl;
        cin >> response;
        // Clear the input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // If no, edit
        if(response == "no") {
            return;
        }

    }
}

void Game::readTreeFromFile(string dictfile) {
    ifstream file(dictfile.c_str()); // converts a string to a character array
    string word;
    // Read in line by line
    while (!file.eof()) { // checks for end of file
        file >> word;
        if (!file.eof()) {
            dict->insert(word);
        }
    }
    return;
}

char* Game::getLetters(int x) {
    // Data
    char full[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char vowel[5] = {'a','e','i','o','u'};
    char* letters = new char[x];
    // Pick
    for(int c=0; c<x/3; ++c) {
        letters[c] = vowel[rand()%5];
    }
    for(int c = x/3; c<x; ++c) {
        letters[c] = full[rand()%26];
    }
    return letters;
}

void Game::getWords() {
    cout << "Type your guesses.\nType \"-1\" to end the round." << endl;
    bool is_end = false;
    // Loop till user enters "-1"
    while(!is_end) {
        // Listen for word guesses
        string response;
        cin >> response;
        // Clear the input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // If -1 then stop inserting words
        if(response == "-1") {
            return;
        }
        // If not end, then add the word to the list
        wordlist->push(response);
    }
}

void Game::checkWordsForScore() {
    // Check the make sure they use valid letters (-1)

    // See if word is in avl tree (+1)

    // Update the player's score

}

bool Game::checkWLetters(string s) {
    // Check to see if string s has valid chars

    // Return true if valid string
    return true;
}
