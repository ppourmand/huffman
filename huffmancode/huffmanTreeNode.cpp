//===========================================================================================
// Pasha Pourmand
// Updated : Mar 4, 2014
// 
//===========================================================================================
#include "huffmanTreeNode.h"
#include <string>

using namespace std;


//===========================================================================================
// Default Constructor
//===========================================================================================
huffmanTreeNode::huffmanTreeNode(){
	character = ' ';
	minChar = ' ';
	frequency = 0;
	left = NULL;
	right = NULL;
}

//===========================================================================================
// Constructor that takes in a character and its frequency
//===========================================================================================
huffmanTreeNode::huffmanTreeNode(char c, int a){
	character = c;
	minChar = c;
	frequency = a;
	left = NULL;
	right = NULL;
}

//===========================================================================================
// Constructor that merges two huffmanTreeNodes together
// This also sets the minimum character as the parent
//===========================================================================================
huffmanTreeNode::huffmanTreeNode(huffmanTreeNode *a, huffmanTreeNode *b){

	frequency = a->getFrequency() + b->getFrequency();
	this->left = a;
	this->right = b;
	// Assigns the minimum character value to the "parent" node
	if(a->minChar < b->minChar){
		minChar = a->minChar;
		//character = b->minChar;
	}
	else{
		minChar = b->minChar;
		//character = a->minChar;
	}

}

//===========================================================================================
// Default Destructor
//===========================================================================================
huffmanTreeNode::~huffmanTreeNode(){

}

//===========================================================================================
// Accessor for freqency of a huffmanTreeNode object
//===========================================================================================
int huffmanTreeNode::getFrequency(){
	return frequency;
}

//===========================================================================================
// Accessor for character of a huffmanTreeNode object
//===========================================================================================
char huffmanTreeNode::getCharacter(){
	return character;
}

//===========================================================================================
// Accessor for left child
//===========================================================================================
huffmanTreeNode* huffmanTreeNode::getLeftChild(){
	return left;
}

//===========================================================================================
// Accessor for right child
//===========================================================================================
huffmanTreeNode* huffmanTreeNode::getRightChild(){
	return right;
}

//===========================================================================================
// Sets the character
//===========================================================================================
void huffmanTreeNode::setCharacter(char c){
	character = c;
}

//===========================================================================================
// Sets the frequency
//===========================================================================================
void huffmanTreeNode::setFrequency(int a){
	frequency = a;
}

void huffmanTreeNode::setHuffmanCode(string a){
	huffmanCode = a;
}

//===========================================================================================
// Sets the left child
//===========================================================================================
void huffmanTreeNode::setLeftChild(huffmanTreeNode *a){
	left = a->getLeftChild();
}

//===========================================================================================
// Sets the right child
//===========================================================================================
void huffmanTreeNode::setRightChild(huffmanTreeNode* a){
	right = a->getRightChild();
}

//===========================================================================================
// Overloads the assignment operator so it doesn't look as messy elsewhere when I swap around
// nodes
//===========================================================================================
huffmanTreeNode& huffmanTreeNode::operator=(const huffmanTreeNode& h){
	//cout << "in assignment operator" << endl;
	if(!(this == &h)){
		character = h.character;
		frequency = h.frequency;
		minChar = h.minChar;

		if(left != NULL){
			delete left;
		}
		if(right != NULL){
			delete right;
		}

		if(h.left != NULL){
			left = new huffmanTreeNode();
			*left = *(h.left);
			if(h.right != NULL){
				right = new huffmanTreeNode();
				*right = *(h.right);
			}
		}
		else{
			left = NULL;
			right = NULL;
		}

	}
	return *this;
}

//===========================================================================================
// 
//===========================================================================================
ostream& operator<<(ostream& os, const huffmanTreeNode& rhs){
    os <<  "\'" << rhs.character << " " << rhs.frequency << " (mchar: "  <<rhs.minChar << ")\' ";
    return os;
}

//===========================================================================================
// Copy Constructor
// POSSIBLY REMOVE THIS
//===========================================================================================
huffmanTreeNode::huffmanTreeNode(const huffmanTreeNode& h){
    //cout << "in copy constructor copying: " << h.character << endl;
     
    if(h.left != NULL){
        left = new huffmanTreeNode();
        *left = *(h.left);
    }
    if(h.right != NULL){
        right = new huffmanTreeNode();
        *right = *(h.right);
    }
    character = h.character;
   	frequency = h.frequency;
   	minChar = h.minChar;
}

//===========================================================================================
// Overloads the < operator so it checks for minchar
//===========================================================================================
bool huffmanTreeNode::operator<(huffmanTreeNode& h){
	if(frequency > h.getFrequency()){
		return true;
	}
	else if(frequency < h.getFrequency()){
		return false;
	}
	else{
		if(minChar > h.minChar){
			return true;
		}
		else{
			return false;
		}
	}
}
