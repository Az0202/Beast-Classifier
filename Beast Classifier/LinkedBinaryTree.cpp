#include "LinkedBinaryTree.h"

LinkedBinaryTree::LinkedBinaryTree()			// constructor
	: _root(NULL), n(0) { }
int LinkedBinaryTree::size() const			// number of nodes
{
	return n;
}
bool LinkedBinaryTree::empty() const			// is tree empty?
{
	return size() == 0;
}
LinkedBinaryTree::Position LinkedBinaryTree::root() const // get the root
{
	return Position(_root);
}
void LinkedBinaryTree::addRoot()			// add root to empty tree
{
	_root = new Node; n = 1;
}
// expand external node
void LinkedBinaryTree::expandExternal(const Position& p) {
	Node* v = p.v;					// p's node
	v->left = new Node;					// add a new left child
	v->left->par = v;					// v is its parent
	v->right = new Node;				// and a new right child
	v->right->par = v;					// v is its parent
	n += 2;						// two more nodes
}
LinkedBinaryTree::Position				// remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
	Node* w = p.v;  Node* v = w->par;			// get p's node and parent
	Node* sib = (w == v->left ? v->right : v->left);
	if (v == _root) {					// child of root?
		_root = sib;					// ...make sibling root
		sib->par = NULL;
	}
	else {
		Node* gpar = v->par;				// w's grandparent
		if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; delete v;					// delete removed nodes
	n -= 2;						// two fewer nodes
	return Position(sib);
}
// list of all nodes
LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
	PositionList pl;
	preorder(_root, pl);					// preorder traversal
	return PositionList(pl);				// return resulting list
}
// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));				// add this node
	if (v->left != NULL)					// traverse left subtree
		preorder(v->left, pl);
	if (v->right != NULL)					// traverse right subtree
		preorder(v->right, pl);
}