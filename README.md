# Beast Classifier

## Description:
Beast Classifier is an interactive expert system utilizing a binary decision tree to classify animals based on user responses. Developed at Piedmont Virginia Community College under the guidance of Professor David Duvall-Early, this system demonstrates the practical application of binary trees in solving classification problems. It dynamically updates its knowledge base by adding new questions and answers through user interactions, enhancing its ability to accurately classify animals over time.

## Features:
* Dynamic Learning: Updates its knowledge base by adding new questions and answers through user interactions.
* Persistent Storage: Saves the decision tree to a file and reloads it upon restart, retaining knowledge between sessions.
* Interactive Interface: Engages users with a simple command-line interface for easy interaction and learning.

## Technologies Used:
* C++
* Binary Trees for decision making

### Compile the project using a C++ compiler:

* g++ -std=c++11 AGG.cpp DecisionTree.cpp LinkedBinaryTree.cpp -o beast_classifier
