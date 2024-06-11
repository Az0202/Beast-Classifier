#include <fstream>
#include <iostream>
#include <string>
#include "DecisionTree.h"
using namespace std;

DecisionTree::DecisionTree(string filename){
    addRoot();
    ifstream check(filename);

    if (check.peek() == ifstream::traits_type::eof()) {
        initializeTree(LinkedBinaryTree::root());
    } else {
        vector<Elem> pre;
        vector<Elem> in;

        bool KEY = false;

        for (Elem text; getline(check, text);) {
            if (text == "KEY") {
                KEY = true;
            } else {
                (KEY ? in : pre).push_back(text);
            }
        }
        check.close();
        int len = in.size();
        buildTreeRecur(pre, in, root(), 0, 0, len - 1);
    }
}

void DecisionTree::insert(LinkedBinaryTree::Position p, Elem question, Elem yesAnswer, Elem noAnswer){
    expandExternal(p);
    *p = question;
    *p.left() = yesAnswer;
    *p.right()= noAnswer;
}

DecisionTree::~DecisionTree(){
    writeTreeToFile();
}

void DecisionTree::initializeTree(LinkedBinaryTree::Position theRoot){
    insert(theRoot, "Are you a mammal?", "kangaroo", "shark");
}

void DecisionTree::writeTreeToFile(){
    ofstream output("decisiontree.dat");
    if (!output) {
        throw runtime_error("File not found");
    }
    PositionList pl = positions();
    PositionList pl2 = positionList2();

    while(!pl.empty()){
        output << *(pl.front()) << endl;
        pl.pop_front();
    }

    output << "KEY" << "\n";

    while(!pl2.empty()){
        output << *(pl2.front()) << endl;
        pl2.pop_front();
    }
    output.close();
}

void DecisionTree::inorder(LinkedBinaryTree::Position pos, PositionList& pl) const{
    if (pos.isExternal()){
        pl.push_back(pos);
    }
    else{
        inorder(pos.left(), pl);
        pl.push_back(pos);
        inorder(pos.right(), pl);
    }
}

size_t indexOf(const vector<Elem>& arr, const Elem& element) {
    size_t index = -1;
    for (size_t i = 0; arr.size(); i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

void DecisionTree::buildTreeRecur(vector<Elem>& preorder, vector<Elem>& inorder, LinkedBinaryTree::Position subRoot, int index, int left, int right){
    if (left > right){
        return;
    }
    else{
        *subRoot = preorder[index++];
        if (left == right){
            return;
        }
        else {
            expandExternal(subRoot);
            int in_index = indexOf(inorder, *subRoot);
            buildTreeRecur(preorder, inorder, subRoot.left(), index, left, in_index - 1);
            buildTreeRecur(preorder, inorder, subRoot.right(), index + in_index - left, in_index + 1, right);
        }
    }
}

LinkedBinaryTree::PositionList DecisionTree::positionList2() const {
    LinkedBinaryTree::PositionList pl;
    inorder(root(), pl);
    return pl;
}
