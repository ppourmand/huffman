//===========================================================================================
// Pasha Pourmand
// Updated : Mar 4, 2014
// 
//===========================================================================================
#ifndef HUFFMANTREENODE_H
#define HUFFMANTREENODE_H

#include <iostream>
#include <string>

using namespace std;

class huffmanTreeNode
{
private:


public:
	int minChar;
	int frequency;
	huffmanTreeNode *left;
	huffmanTreeNode *right;
	unsigned char character;
	string huffmanCode;

	huffmanTreeNode(); 
	huffmanTreeNode(char c, int a);
	huffmanTreeNode(const huffmanTreeNode&);
	huffmanTreeNode(huffmanTreeNode *a, huffmanTreeNode *b);
	~huffmanTreeNode();

	int getFrequency();
	void setFrequency(int a);
	char getCharacter();
	void setCharacter(char c);
	void setHuffmanCode(string a);

	void setLeftChild(huffmanTreeNode* a);
	void setRightChild(huffmanTreeNode* b); 
	huffmanTreeNode* getLeftChild();
	huffmanTreeNode* getRightChild();

	huffmanTreeNode& operator=(const huffmanTreeNode& node);
	friend ostream& operator<<(ostream&, const huffmanTreeNode&);
	bool operator< (huffmanTreeNode&);

};


#endif