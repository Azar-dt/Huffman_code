#include <bits/stdc++.h>
#include "huffman_func.hpp"

using namespace std; 

int main() { 
    string s;
    string file_name; 
    node* root; 
    ifstream fi; 
    int choose; 

    do { 
        cout<<"\tHUFFMAN_CODE\t"<<endl; 
        cout<<"1.ENCODE FILE TEXT"<<endl; 
        cout<<"2.DECODE FILE TEXT"<<endl; 
        cout<<"3.EXIT"<<endl; 
        cout<<"CHOOSE : "; cin>>choose;
        switch (choose)
        {
        case 1:
            cout<<"INPUT NAME FILE U WANT TO ENCODE: "<<endl; 
            cin>>file_name;
            fi.open(file_name.c_str());  
            getline(fi,s); 
            fi.close(); 
            root = huffman_code(s); 
            encode(s); 
            // print encode in file encode.txt
            break;
        case 2: 
            cout<<"INPUT NAME FILE U WANT TO DECODE : "<<endl; 
            cin>>file_name;
            fi.open(file_name.c_str());  
            getline(fi,s); 
            fi.close(); 
            decode(s,root); 
            // print decode in file decode.txt
        case 3: 
            return 0; 
        default:
            break;
        } 
    }  while (1); 

    return 0; 
}