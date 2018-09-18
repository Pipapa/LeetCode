#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class MapSum {
public:

    struct TrieNode{
        int sum;
        bool used;
        TrieNode *arr[27];
        TrieNode():sum(0),used(false){for(int i=0;i<27;i++) arr[i]=NULL;}
    };

    TrieNode *root;

    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        int old_num=0;
        TrieNode *loop = root;
        for(char ch : key){
            int tmpc = ch - 'a';
            if(loop->arr[tmpc] == NULL){
                loop->arr[tmpc] = new TrieNode();
                loop->arr[tmpc]->arr[26] = loop;
            }
            loop = loop->arr[tmpc];
        }
        loop->used = true;
        int des=0;
        for(int i=0;i<26;i++){
            if(loop->arr[i]) des += loop->arr[i]->sum;
        }
        des = val-(loop->sum - des);
        while (loop){
            loop->sum += des;
            loop = loop->arr[26];
        }
    }

    int sum(string prefix) {
        TrieNode *loop = root;
        for(char ch : prefix){
            if(loop == NULL) break;
            loop = loop->arr[ch - 'a'];
        }
        return  loop?loop->sum:0;
    }
};

int main() {
    MapSum *obj = new MapSum();
    obj->insert("apple",3);
    obj->insert("apple",3);
    cout << obj->sum("ap") << endl;
    obj->insert("ap",7);
    cout << obj->sum("ap") << endl;
    obj->insert("ap",2);
    cout << obj->sum("ap") << endl;
    return 0;
}