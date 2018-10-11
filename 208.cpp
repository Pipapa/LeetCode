#include <string>
#include <iostream>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        TrieNode *chs[26];
        bool used;
        TrieNode():used(false){for(int i=0;i<26;i++) chs[i]=NULL;}
    };
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *loop = root;
        for(char ch : word){
            if(loop->chs[ch-'a'] == NULL)
                loop->chs[ch-'a'] = new TrieNode();
            loop = loop->chs[ch-'a'];
        }
        loop->used = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *loop = root;
        for(char ch : word){
            if(!loop->chs[ch-'a']) return false;
            loop = loop->chs[ch-'a'];
        }
        return loop->used;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *loop = root;
        for(char ch : prefix){
            if(!loop->chs[ch-'a']) return false;
            loop = loop->chs[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(){
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    return 0;
}
