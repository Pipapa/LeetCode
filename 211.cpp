#include <string>
#include <iostream>
#include <queue>
using namespace std;


class WordDictionary {
public:
    struct TrieNode{
        TrieNode * chs[26];
        bool used;
        TrieNode():used(false){for(int i=0;i<26;i++) chs[i]=NULL;}
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *loop = root;
        for(char ch : word){
            if(loop->chs[ch-'a'] == NULL) loop->chs[ch - 'a'] = new TrieNode();
            loop = loop -> chs[ch - 'a'];
        }
        loop->used = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *loop = root;
        vector<TrieNode*> nodes;
        nodes.push_back(loop);

        for(char ch : word){
            vector<TrieNode*> tmp_nodes;
            if(nodes.size() == 0) return false;
            for(int i=0;i<nodes.size();i++){
                TrieNode *tmpn=nodes[i];
                if(ch == '.'){
                    for(int i=0;i<26;i++) if(tmpn->chs[i]) tmp_nodes.push_back(tmpn->chs[i]);
                }else if(tmpn->chs[ch - 'a']) tmp_nodes.push_back(tmpn->chs[ch - 'a']);
            }
            nodes = tmp_nodes;
        }
        for(int i=0;i<nodes.size();i++)
            if(nodes[i]->used== true) return true;
        return false;
    }
};

int main(){
    WordDictionary d;
    d.addWord("a");
    d.addWord("a");
    cout << d.search(".") << endl;
    cout << d.search("a") << endl;
    cout << d.search("aa") << endl;
    cout << d.search("a") << endl;
    cout << d.search(".a") << endl;
    cout << d.search("a.") << endl;
    return 0;
}