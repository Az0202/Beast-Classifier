#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include <fstream>
#include <string>
#include <vector>
#include "LinkedBinaryTree.h"
typedef string Elem;
class DecisionTree: public LinkedBinaryTree {
    public:
        DecisionTree(string filename); //constructor
        void insert(LinkedBinaryTree::Position p, Elem question, Elem yesAnswer, 
Elem noAnswer);
        ~DecisionTree();
    private:
        string treeFileName;
        void initializeTree(LinkedBinaryTree::Position theRoot);
        void writeTreeToFile();
PositionList positionList2() const;  //list of nodes from inorder traversal
void inorder(LinkedBinaryTree::Position pos, PositionList& pl) const; // inorder utility
void buildTreeRecur(vector<Elem>& preorder, vector<Elem>& inorder, 
LinkedBinaryTree::Position subRoot, int index, int left, int 
right); 
};
#endif /* DECISIONTREE_H */