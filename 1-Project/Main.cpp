#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    //LL* temp = new LL();
    //temp->push("Hello");
    //temp->push("World!");
    //
    //temp->printList();

    Game* game = new Game("dict-short.txt");

    //game->dict->printTreeio();
    //game->wordlist->printList();

    cout << "Number right: " << game->numright << endl;
    cout << "Total guesses: " << game->totalwords << endl;

    //bool temp = game->dict->search("aa");


}
