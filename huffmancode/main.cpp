//===========================================================================================
// Pasha Pourmand
// Updated : Mar 13, 2014
//===========================================================================================
#include <iostream>
#include <string>
#include "huffmanTreeNode.h"
#include "minheap.h"
#include "huffman.h"

using namespace std;

//===========================================================================================
// Main Function
//===========================================================================================
int main(int argc, char *argv[]){

	huffman myHuffmanTree;

 	if(argc == 2 && strncmp(argv[argc - 1], "-d", 2) == 0){
 		//myHuffmanTree.readInCompress();
 	}
  	else{
  		// Reads in the frequencies and characters
    	myHuffmanTree.readIn();

    	// Creates the huffman tree
    	// TODO: make sure properly creating heap with the correct determinism
    	myHuffmanTree.createHuffTree();

    	// Write out all the compressed data
    	myHuffmanTree.writeCompressedToOutput();
  	}



	return 0;
}