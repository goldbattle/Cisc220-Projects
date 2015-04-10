#include <fstream>
#include <string>
#include "Game.h"
#include "BSTY.h"

using namespace std;

Game::Game() {
    // Call sub-construtor
    Game("dict.txt");
}

Game::Game(string infile) {
    // Read in the dictionary
    readTreeFromFile(infile);
    // Init linked list
    wordlist = new LL();
    //TODO: Start the game

}


void Game::startGame() {

}

void Game::readTreeFromFile(string dictfile) {
    dict = new BSTY();
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
    char* a = new char('a');
    return a;
}

void Game::getWords() {

}

bool Game::checkWLetters(string s) {
    return true;
}

void Game::checkWordsForScore() {

}
