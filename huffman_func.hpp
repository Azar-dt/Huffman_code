#include <bits/stdc++.h>

using namespace std; 

typedef map<char,int> hmap; 
typedef struct min_heap_node { 
    char data ; 
    int freq; 
    min_heap_node * left; 
    min_heap_node * right;  
    
} node;

struct compare_freq{ 
    bool operator()(node* a,node* b) 
    { 
        return a->freq > b->freq; 
    }
}; 

hmap get_freq(string s); 

bool isleaf(node* x); 

node* make_node(char ch, int fre); 

node* huffman_code(string s); 

void get_encode(node* root,string str,map<char,string>& en_code); 

void encode(string s); 

void decode(string s, node* root); 