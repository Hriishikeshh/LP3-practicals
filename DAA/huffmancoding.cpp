#include<bits/stdc++.h>
using namespace std;

struct huffmannode{
    huffmannode* left;
    huffmannode* right;
    int freq;
    char data;

    huffmannode(char data,int freq){
        left=right=nullptr;
        this->data=data;
        this->freq=freq;
    }
};

struct compare{
    bool operator()(huffmannode* left,huffmannode* right){
        return left->freq > right->freq;
    }
};

void printhuffmancode(huffmannode* root,string str){
    if(!root) return;
    if(root->data!='$'){
        cout<<root->data<<":"<<str<<"\n";
    }

    printhuffmancode(root->left,str+"0");
    printhuffmancode(root->right,str+"1");
}

void huffmanEncoding(vector<int> freq,vector<char> letters,int size){
    priority_queue<huffmannode*,vector<huffmannode*>,compare> pq;
    for(int i=0;i<size;i++){
        pq.push(new huffmannode(letters[i],freq[i]));
    }

    if(pq.empty()) return;

    while(pq.size()>1){
        huffmannode* left=pq.top();
        pq.pop();
        huffmannode* right=pq.top();
        pq.pop();

        huffmannode* top=new huffmannode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;

        pq.push(top);
    }
    printhuffmancode(pq.top(),"");
}

int main(){
    string str;
    if(!(cin>>str)) return 0;
    map<char,int>mp;
    for(char ch: str){
        mp[ch]++;
    }
    vector<int> freq;
    vector<char> letters;
    for(auto it:mp){
        letters.push_back(it.first);
        freq.push_back(it.second);
    }
    if(letters.empty()) return 0;
    huffmanEncoding(freq,letters,letters.size()); 
    return 0;
}

