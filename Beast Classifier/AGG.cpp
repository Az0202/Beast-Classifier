#include "DecisionTree.h"
#include <iostream>
#include "LinkedBinaryTree.h"
#include <string>

using namespace std;

int main(){
    ifstream input("decisiontree.dat");  
    DecisionTree game = DecisionTree("decisiontree.dat");
    DecisionTree::Position pos = game.root(); //position of root
    bool run;
    run = true;
    cout << "Welcome to the Animal Guessing Game! I will\nask you a sequence of questions with yes or no\nanswers and then I will make a guess.  Ready?  \nHere goes!!\n";
    while (run) {
        char ans = 'a';
        char last= 'a';
        while (!pos.isExternal()) {
            char in;
            cout << "\n" << *pos <<  "  [y or n]: ";
            cin >> in;
            cout << "\n";
            if (in == 'y') {
                pos = pos.left();
            }
            else if (in == 'n') {
                pos = pos.right();
            }
            else {
                cout << "\nPlease enter the letter y or the letter n to respond.\n";
            }
        }
        cout << "\nMy guess is " << *pos << ".  Am I right? [y or n]: ";
        cin >> ans;
        cout << "\n";
        if (ans == 'n') {
            string q = "";
            string a = "";
            string temp = *pos;
            char yorn= 'a';
            cout << "\nI give up.  What are you? ";
            cin.ignore(256, '\n');
            getline(std::cin, a);
            cout << "\n\nPlease type a question that will distinguish a " << a << " from a " << *pos << ":  ";
            getline(std::cin, q);
            cout << "\n\nIs the answer to that question " << a << "? [y or n]: ";
            while (yorn != 'y' && yorn != 'n') {
                cin >> yorn;
                cout << "\n";
                if (yorn == 'y') {
                    game.insert(pos, q, a, temp);
                }
                else if (yorn == 'n') {
                    game.insert(pos, q, temp, a);
                }
                else {
                    cout << "\nPlease enter the letter y or the letter n to respond.\n";
                }
            }
        }
        cout << "\nShall we play again? [y or n]: ";
        cin >> last;
        cout << "\n";
        if (last == 'n') {
            cout << "\nThank you for teaching me a thing or two.\n";
            run = false;
        }
        if (last == 'y') { 
            pos = game.root();
        }
    }
}
