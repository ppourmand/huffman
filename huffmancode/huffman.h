//===========================================================================================
// Pasha Pourmand
// Updated : Mar 4, 2014
// 
//===========================================================================================
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include "huffmanTreeNode.h"
#include "minHeap.h"

using namespace std;

class huffman
{
private:
	unsigned int frequencies[256];
	string codebook[256];
	int countForHeap;
	minHeap myHeap;
	string input;

public:
	huffman(); 
	void createHuffTree();
	void traversal(huffmanTreeNode* rootNode, string huffcode);
	void encodeCharacters();
	void printOutCodes();
	void makeHuffmanTree(minHeap &h, int a);
	void readInCompress();
	void readIn();
	void writeCompressedToOutput();
	string lookup(char c);
	~huffman();
	void bitwise();
	void decompress();
	
};


#endif