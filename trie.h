//Prefix Trie
//CPSC 4520
//HWTwo

#ifndef TRIE_H
#define TRIE_H
#include <string>
using namespace std;
#define ALPHABET (255)
//the alphabet is 26 letters and spaces

struct node{
    struct node *children[ALPHABET];
    int count;
    double longitude;
    double latitude;
    bool isLeaf;
};

class trie{
    private:

    public:
	node *root;
	trie();
	~trie();
	struct node* newNode();
	void insert(string key, double longitude, double latitude);
	struct node* search(string key);
};

#endif





