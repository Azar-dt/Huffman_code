#include <bits/stdc++.h>
#include "huffman_func.hpp"

using namespace std; 

hmap get_freq(string s) { 
    hmap freq; 
     
    for (int i=0; i<s.length() ; i++ ) { 
        freq[s[i]] = 0; 
    }

    for (int i=0; i<s.length(); i++ ) { 
        freq[s[i]]++ ;  
    }
    return freq; 
}

bool isleaf(node* x) { 
    return x->left==NULL&&x->right==NULL ; 
}

node* make_node(char ch, int fre) { 
    node* temp = new node() ; 
    temp->data = ch; 
    temp->freq = fre; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
}

node* huffman_code(string s) {
    hmap fre = get_freq(s);  
    priority_queue < node*, vector< node* >,compare_freq > q; 
    
    for(auto x: fre) {  
        
        node* temp = make_node(x.first,x.second); 
        //cout<<temp->data<<" "<<temp->freq<<endl; 
        q.push(temp); 
        //cout<<q.top()->data<<" "<<q.top()->freq<<endl; 
    }
    node* l; 
    node * r;
    
    while (q.size() != 1) { 
        l = q.top(); q.pop(); 
        r = q.top(); q.pop(); 
        
        node* temp = make_node('$',l->freq + r->freq); 
       
        temp->left = l; 
        temp->right = r; 
        
        q.push(temp); 

    }
    node* root = q.top(); 
    return root; 
}

void get_encode(node* root,string str, map<char,string>& en_code) { 
    if (root == nullptr) return; 
    if (isleaf(root)) { 
        en_code[root->data] = str; 
    }
    get_encode(root->left,str+"0",en_code); 
    get_encode(root->right,str+"1",en_code); 
}

void encode(string s) { 
    node* root = huffman_code(s); 
    //cout<<root->data<<" "<<root->freq<<endl; 
    map<char,string> en_code; 
    string str =""; 
    get_encode(root,str,en_code); 
    
    fstream fo("encode.txt",ios::out); 
    for(int i=0;i<s.length(); i++) { 
        fo<<en_code[s[i]]; 
    }

}

void decode(string s, node* root) { 
    node* temp = root; 
    fstream fo("decode.txt",ios::out); 
    for(int i=0;i<s.length();i++) { 
        if (s[i] == '0') { 
            temp = temp->left; 
        }
        else temp = temp->right; 
        if (isleaf(temp)) { 
            fo<<temp->data; 
            temp = root;
        }
    }
}