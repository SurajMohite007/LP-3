#include<bits/stdc++.h>
using namespace std;



struct Huffmannode{
    Huffmannode* left;
    Huffmannode* right;
    char data;
    int freq;

    Huffmannode(char data,int freq){
        left=NULL;
        right= NULL;
        this->data=data;
        this->freq=freq;
    }

};

struct Compare{
    bool operator()( Huffmannode* left,Huffmannode* right){
        return left->freq>right->freq;
    }
};

void printCodes(Huffmannode *root,string code, unordered_map<char,string> &mp){    

    if(!root){
        return;
    }

    if(!root->left && !root->right){
        mp[root->data]= code;
        cout<<root->data<<" : "<< code<<endl;
    }

    printCodes(root->left,code+"0",mp);
    printCodes(root->right,code+"1",mp);

}

void createHauffmanTree(const string& text){
    unordered_map<char,int> freqMap;
    for(auto ch:text){
        freqMap[ch]++;
    }
    priority_queue<Huffmannode*,vector<Huffmannode*>,Compare> pq;
    for(auto pr:freqMap){
        pq.push(new Huffmannode(pr.first,pr.second));
    }

    while(pq.size()>1){

        Huffmannode* left = pq.top();
        pq.pop();
        Huffmannode* right = pq.top();
        pq.pop();

        Huffmannode* newnode = new Huffmannode('\0',left->freq+right->freq);

        newnode->left=left;
        newnode->right=right;

        pq.push(newnode);
    }
    Huffmannode* root = pq.top();
    pq.pop();

    unordered_map<char,string> maps;

    printCodes(root,"",maps);

    for(auto ch:text){
        cout<<maps[ch];
    }
    cout<<endl;
}
int main(){
    string s;
    cout<<"Please enter the input string: ";
    getline(cin,s);
    createHauffmanTree(s);

    return 0;
}