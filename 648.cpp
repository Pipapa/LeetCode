#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct TrieNode{
        TrieNode *ch[26];
        bool used;
        TrieNode():used(false){for(int i=0;i<26;i++) ch[i]=NULL;}
    };
    TrieNode *root;
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        string ans = "";
        for(string str : dict){   // Build the tree
            TrieNode* loop = root;
            for(char c : str){
                if(loop->ch[c - 'a'] == NULL){
                    TrieNode *n_node = new TrieNode();
                    loop->ch[c-'a'] = n_node;
                    loop = n_node;
                }else loop = loop->ch[c - 'a'];
            }
            loop->used = true;
        }
        int cnt = 0;
        TrieNode* loop = root;
        while(sentence[cnt] != '\0'){
            if(sentence[cnt] == ' ') loop = root,ans+=' ',cnt++;
            else if(loop->ch[sentence[cnt] - 'a']){
                if(loop->ch[sentence[cnt] - 'a']->used) {
                    ans += sentence[cnt];
                    while(sentence[cnt] != ' ' && sentence[cnt]!='\0') cnt++;
                }else{
                    loop = loop->ch[sentence[cnt] -'a'];
                    ans += sentence[cnt++];
                }
            }else{
                while(sentence[cnt+1] != ' ' && sentence[cnt+1]!='\0') ans+=sentence[cnt++];
                ans+=sentence[cnt++];
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> dict = {"cat", "bat", "rat"};
    cout << s.replaceWords(dict,"the cattle was rattled by the battery") << endl;
    return 0;
}

