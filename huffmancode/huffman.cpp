#include "huffman.h"
#include "huffmanTreeNode.h"
#include "minheap.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

huffman::huffman(){

	// Loops for default values
	for(int i = 0; i < 256; i++){
		codebook[i] = "";
	}
	for(int i = 0; i < 256; i++){
		frequencies[i] = 0;
	}
}

huffman::~huffman(){

}

//===========================================================================================
// NOT DONE
// Creates min heap, inserts, traverses
//===========================================================================================
void huffman::createHuffTree(){
	huffmanTreeNode* a;
	huffmanTreeNode* b;

	// Initial insertion into the min heap
	for(int i = 0; i < 256; i++){
		if(frequencies[i] != 0){
			a = new huffmanTreeNode((char)i, frequencies[i]);
			myHeap.push(a);
		}
	}
	// Loops until 1 node left in the min heap
	while(myHeap.heapSize > 1){
		//myHeap.inOrder(0);
		//cout << "---" << endl;
		a = myHeap.top();
		myHeap.pop();
		b = myHeap.top();
		myHeap.pop();

		if(*(a) < *(b)){
			myHeap.push(new huffmanTreeNode(a, b));
		}
		else{
			myHeap.push(new huffmanTreeNode(b, a));
		}
	}

	// Traverese the min heap and assigns 0 if left, 1 if right
	traversal(myHeap.top(), "");
	//printOutCodes();
}

//===========================================================================================
// Traverses the Huffman tree to assign 0's and 1's
//===========================================================================================
void huffman::traversal(huffmanTreeNode* rootNode, string huffcode){
	// If done
	if(rootNode->getLeftChild() == NULL){
		rootNode->setHuffmanCode(huffcode);
		codebook[(int)(rootNode->getCharacter())] = huffcode;
		return;
	}
	// Otherwise
	else{
		// Go left and recurse
		traversal(rootNode->getLeftChild(), huffcode+"0");

		// Go right and recurse
		traversal(rootNode->getRightChild(), huffcode+"1");
	}
}

//===========================================================================================
// Prints out the codebook
//===========================================================================================
void huffman::printOutCodes(){
	for (int i = 0; i < 256; i++) {
		if(codebook[i] != ""){
			cout << (char) i << " " << i << " " << codebook[i] << endl;
		}
  	}
}

//===========================================================================================
// looks up the code based on the letter
//===========================================================================================
string huffman::lookup(char c){
	return codebook[(int)c];
}

//===========================================================================================
// Reads in compressed data
//===========================================================================================
void huffman::readInCompress(){
	string cookie;

	// Put the cookie into a string
	for(int i = 0; i < 8; i++){
		cookie = cin.get();
	}

	// Read in
	//for(int i = 0; i < 256; i++){
	//	cin.read((char*) &frequencies[i], 4);
    //    countForHeap += frequencies[i];
	//}
	getline(cin, input, '\0');
	
	for(int i = 0; i < input.length(); i++){
		frequencies[(int)input[i]] +=1;
	}

	// Creates the tree
	createHuffTree();

	// Decompress
	decompress();

}

void huffman::decompress(){
	//unsigned char myBuffer;
	//unsigned int numberPrinted = 0;
	// *huffmanNode = myHeap.top();

	//
	//if(huffmanNode.getLeftChild() == NULL && huffmanTreeNode.getRightChild() == NULL){

//
}

//===========================================================================================
// NOT DONE
// Writes all the compressed data to output (use xxd)
//===========================================================================================
void huffman::writeCompressedToOutput(){
	// Prints the magic cookie
	cout << "HUFFMA5" << '\0';

	// Writes out the frequencies
	for (int i = 0; i < 256; i++) {
    	cout.write((const char*) &frequencies[i], sizeof(frequencies[i]));
  	}

	// Writes outs the Data
  	bitwise();
}

//===========================================================================================
// DONE
// reads in the frequencies
//===========================================================================================
void huffman::readIn(){
	countForHeap = 0;

	//getline(cin, input, '\0');

	//cout << input << endl;
	//-input += '\n';
	
	//for(int i = 0; i < input.length(); i++){
	//	if(input[i] < 256){
	//		frequencies[(int)input[i]] +=1;
	//	}
//	}

	while(!cin.eof()){
		frequencies[cin.get()] += 1;
		countForHeap += 1;
	}

	// Resets instream pointer
	cin.clear();
	cin.seekg(0);
}

//===========================================================================================
// Converts to bits
//===========================================================================================
void huffman::bitwise(){
	int nextChar = 0;
	int widthOfByte = 0;
    unsigned char byteBuffer = 0;

    //cout << inputString << endl;
    
    // Lopps through the input character by character
   // for(int j = 0; j < input.length(); j++){
    while(!cin.eof()){
    	nextChar = cin.get();

    	if(nextChar <0 ){
    		break;
    	}

    	// Encodes
    	for (int i = 0; i < codebook[nextChar].size(); i++) {
            byteBuffer += (((int) codebook[nextChar].at(i)) - '0') << 7;
            widthOfByte += 1;

            // If we have a full byte, print dat shit out
            if (widthOfByte == 8) {
                cout.write((char*) &byteBuffer, 1);
                widthOfByte = 0;
                
                // Resets the byte buffer
                byteBuffer = 0;
            }

            // Otherwise, 
            else{
                byteBuffer = byteBuffer >> 1;
            }
        }


    	
    }
      	
    byteBuffer = byteBuffer >> (7 - widthOfByte);
    cout.write((char*) &byteBuffer, 1);
}
