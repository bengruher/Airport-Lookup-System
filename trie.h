//Prefix Trie
//CPSC 5520
//HW4

#ifndef TRIE_H
#define TRIE_H
#include <string>
using namespace std;
#define ALPHABET (255)
//255 is excessive, however several cities have
//accent marks and characters that don't fit neatly
//on the alphabet. we use the length of the ascii 
//table to ensure they dont get dropped. since the
//server only runs once and is called by all clients
//this is a drawback we are willing to take for better
//usability

struct node{
    struct node *children[ALPHABET];
    int count;
    double longitude;
    double latitude;
    bool isLeaf;
};

class trie{
    private:
	node *root;
    public:
	trie();
	~trie();
	struct node* newNode();
	void insert(string key, double longitude, double latitude);
	struct node* search(string key);
};

#endif




