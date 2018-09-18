#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


struct TrieNode{
    TrieNode* arr[27];
    bool used;
    TrieNode(){for(int i=0;i<27;i++) arr[i]=NULL;used= false;}
};

void insert(TrieNode *root,string s){
    TrieNode *loop = root;
    for(char ch : s){
        int index = ch - 'a';
        if(loop->arr[index] == NULL){
            loop->arr[index] = new TrieNode();
            loop->arr[index]->arr[26] = loop;
        }
        loop = loop->arr[index];
    }
    loop->used = true;
}

string longestWord(vector<string>& words) {
    TrieNode *root = new TrieNode();
    for(string str : words) insert(root,str);
    queue<TrieNode *> q;
    TrieNode *ans,*loop;
    q.push(root);
    while(!q.empty()){
        ans = q.front(); q.pop();
        for(int i=25;i>=0;i--){
            if(ans->arr[i] == NULL)
                continue;
            if(ans->arr[i]->used) q.push(ans->arr[i]);
        }
    }
    string ansstr = "";
    loop = ans->arr[26];
    while (loop){
        for(int i=0;i<26;i++){
            if(loop->arr[i] == ans){
                ansstr = (char)(i+'a') + ansstr;
            }
        }
        ans = loop;
        loop = loop->arr[26];
    }

    return ansstr;
}


int main() {
    vector<string> ch={"apple","apply","ap","appl","app","banana","a"};
    longestWord(ch);
    return 0;
}