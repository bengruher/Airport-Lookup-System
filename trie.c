//Prefix Trie
//CPSC 5520
//HW4


#include "trie.h"

using namespace std;

//node struct setup:
//*children[26]
//count
//long and lat
//bool isLeaf

trie::trie(){
    root = newNode();
}

void recursDelete(node* root){
    for(int i = 0; i <= ALPHABET; i++){
	recursDelete(root->children[i]);
    }
    delete root;
}

trie::~trie(){
    recursDelete(root);
}

//make new empty node
struct node* trie::newNode(){
    struct node *currNode = new node();
    
    //initialize all to null
    currNode->count = 0;
    currNode->isLeaf = false;
    currNode->longitude = 0;
    currNode->latitude = 0;
    for(int i = 0; i < ALPHABET; i++){
        currNode->children[i] = NULL;
    }
    return currNode;
}


void trie::insert(string key, double inLongitude, double inLatitude){
    int depth;
    int keyLength = key.length();
    int index;
    
    if(root == nullptr){
	root = newNode();
    }

    struct node *currNode = root;

    for(depth = 0; depth < keyLength; depth++){
	//find the index for the array of pointers by pulling
	//the char from key that is at the current depth of
	//the tree
	index = key[depth];
	if(currNode->children[index] == NULL){
	    currNode->children[index] = newNode();
	    currNode->count++;
	}
	
	currNode = currNode->children[index];
    }

    currNode->isLeaf = true;
    currNode->longitude = inLongitude;
    currNode->latitude = inLatitude;
}

struct node* trie::search(string key){
    int depth;
    int keyLength = key.length();
    int index;

    struct node *currNode = root;

    for(depth = 0; depth < keyLength; depth++){
	//find index same as insert above
	index = key[depth];
	if(!currNode->children[index]){
	    return NULL;
	}
	currNode = currNode->children[index];
    }
    //if its a leaf, return the node
    if (currNode->isLeaf == true){
	return currNode;
    }
    else{
	//we need to move down the rest of the tree if there
	//is only one completion option for the prefix
	while (!currNode->isLeaf){
	    if (currNode->count != 1){
		return NULL;
	    }
	    index = 0;
	    while (!currNode->children[index]){
		index++;
	    }
	    currNode = currNode->children[index];
	}
	return currNode;
    }
}


