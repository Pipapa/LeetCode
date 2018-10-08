#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class MagicDictionary {
public:
#define ANYONE 26
    struct TrieNode{
        TrieNode *chs[27];
        TrieNode():used(0),flag(0){for(int i=0;i<27;i++) chs[i]=NULL;};
        int used,flag;
    };

    TrieNode *root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {

        for(string str : dict){
            queue<TrieNode*> node_queue;
            int loop_num = 1;
            node_queue.push(root);

            for(int cnt_ch=0;cnt_ch < str.length();++cnt_ch){
                char ch = str[cnt_ch];
                for(int i=1;i<=cnt_ch+1;i++){
                    TrieNode *loop = node_queue.front();node_queue.pop();
                    if(loop->chs[ch-'a'] == NULL){
                        TrieNode *n_node = new TrieNode();
                        n_node->flag = loop->flag;
                        loop->chs[ch-'a'] = n_node;
                        node_queue.push(n_node);
                    }else node_queue.push(loop->chs[ch-'a']);
                    if(loop->chs[ANYONE] == NULL && loop->flag == 0){
                        TrieNode *n_node = new TrieNode();
                        n_node->flag = 1;
                        loop->chs[ANYONE] = n_node;
                        node_queue.push(n_node);
                    }else if(loop->chs[ANYONE]) node_queue.push(loop->chs[ANYONE]);
                }
            }
            while(!node_queue.empty()){
                node_queue.front()->used ++;
                node_queue.pop();
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode* loop = root;
        queue<TrieNode*> node_queue;
        node_queue.push(root);
        int cnt = 1;
        for(char ch : word){
            int n=0;
           for(int i=1;i<=cnt;i++){
               if(node_queue.empty()) return false;
               TrieNode* tmp = node_queue.front();node_queue.pop();
               if(tmp->chs[ch - 'a']) node_queue.push(tmp->chs[ch - 'a']),n++;
               if(tmp->chs[ANYONE]) node_queue.push(tmp->chs[ANYONE]),n++;
           }
           cnt = n;
        }
        if(node_queue.empty()) return false;
        int flag=1;
        while(!node_queue.empty()){
            if(node_queue.front()->used >= 2) return true;
            if(node_queue.front()->used == 1 && node_queue.front()->flag == 0) flag=0;
            if(node_queue.front()->used == 1 && node_queue.front()->flag == 1 && flag == 1) return true;
            node_queue.pop();
        }
        return false;
    }
};

int main(){
    vector<string> test={"hello","hallo","leetcode"};
    MagicDictionary d;
    d.buildDict(test);
    cout << d.search("hello") << endl;
    cout << d.search("hhllo") << endl;
    cout << d.search("hell") << endl;
    cout << d.search("leetcoded") << endl;
    return 0;
}