//===========================================================================================
// Pasha Pourmand
// Updated : Mar 4, 2014
// 
//===========================================================================================
#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <string>
#include "huffmanTreeNode.h"

using namespace std;

class minHeap
{
private:
	huffmanTreeNode *nodes[256];

public:
	minHeap();
	minHeap(int a);
	~minHeap();
	int heapSize;

	void push(huffmanTreeNode* a);
	void pop();
	void heapifyUp(int index, int);
	void heapifyDown(int index);
	void inOrder(int);
	huffmanTreeNode* top();

};
#endif
