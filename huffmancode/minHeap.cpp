//===========================================================================================
// Pasha Pourmand
// Updated : Mar 8, 2014
// 
//===========================================================================================
#include "minHeap.h"
#include "huffmanTreeNode.h"

//===========================================================================================
// Default Constructor
//===========================================================================================
minHeap::minHeap():heapSize(0){
	//heapSize = 0;
}

//===========================================================================================
// Default Destructor
//===========================================================================================
minHeap::~minHeap(){

}

//===========================================================================================
// Function that inserts a new node to the left of the tree, then reheapifies if needed
//===========================================================================================
void minHeap::push(huffmanTreeNode* a){

	// If the heapSize of the heap is 0
	// increment the heapSize of the heap by 1
	if(heapSize == 0){
		nodes[heapSize] = a;
		heapSize++;
	}
	// Otherwise, just insert it and heap up
	// in case the parent is larger
	else{
		nodes[heapSize] = a;
		heapSize++;
		heapifyUp(heapSize - 1, (heapSize - 2) / 2);
	}	

}

//===========================================================================================
// Deletes the top node from the heap, moves the last one to be in its places and 
// calls heapifyDown in order to establish min-heap properties again
//===========================================================================================
void minHeap::pop(){

	// Move top node to last position
	nodes[0] = nodes[heapSize - 1];

	// Set the last position to NULL, erasing it
	nodes[heapSize - 1] = NULL;

	// Decrease the heapSize
	heapSize--;

	// Heap down
	heapifyDown(0);
}

//===========================================================================================
// Checks to see if the newly added node needs to be heapified up the tree
//===========================================================================================
void minHeap::heapifyUp(int child, int parent){

	huffmanTreeNode *temporary;

	// Base case
	if(child == 0){
		return;
	}

	// If the parent is less than the child
	// swap them and heap up
	if(*(nodes[parent]) < *(nodes[child])){
		temporary = nodes[parent];
		nodes[parent] = nodes[child];
		nodes[child] = temporary;
		heapifyUp(parent, (parent - 1)/ 2);
	}


}


//===========================================================================================
// Used for going back down once you've popped out the root of a min heap
//===========================================================================================
void minHeap::heapifyDown(int index){
	huffmanTreeNode *temp;
	int left = index * 2 + 1;
	int right = index * 2 + 2;

	// If two children
	if(right <= heapSize - 1){
		// If parent is less than left child or parent is less than right child
		if(*(nodes[index]) < *(nodes[left]) || *(nodes[index]) < *(nodes[right])){
			// If left child is less than right child
			// swap
			if(*(nodes[left]) < *(nodes[right])) {
	                temp = nodes[index];
	                nodes[index] = nodes[right];
	                nodes[right] = temp;
	                heapifyDown(right);
	            }
	        else{
	            temp = nodes[index];
	            nodes[index] = nodes[left];
	            nodes[left] = temp;
	            heapifyDown(left);
	        }
	    }
	}
	// If one child
	else if(left <= heapSize - 1) {
		// If parent nodes is less than left node
	    if(*(nodes[index]) < *(nodes[left])) {
	        temp = nodes[index];
	        nodes[index] = nodes[left];
	       	nodes[left] = temp;
	        heapifyDown(left);
        }
    }
}

//===========================================================================================
// Function that allows us to see what is at the top (ie the minimum) of the tree
//===========================================================================================
huffmanTreeNode* minHeap::top(){
	return nodes[0];
}

//===========================================================================================
// 
//===========================================================================================
void minHeap::inOrder(int curIndex){
	//if(((2*curIndex+1) < heapSize) && (nodes[2*curIndex+1] != NULL)) inOrder(2*curIndex+1);
    //cout << *nodes[curIndex] << " ";
    //if(((2*curIndex+2) < heapSize) && (nodes[2*curIndex+2] != NULL)) inOrder(2*curIndex+2);
	for(int i = 0; i < heapSize; i++){
		cout << *nodes[i] << endl;
	}

}









