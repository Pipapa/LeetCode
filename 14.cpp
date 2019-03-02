#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct TrieNode{
        bool used;
        TrieNode *chs[26];
        TrieNode():used(false){for(int i=0;i<26;++i)chs[i]=NULL;}
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode *root = new TrieNode;
        string result = "";
        for(int i=0;i<strs.size();++i){
            TrieNode *loop = root;
            string str = strs[i];
            for(int p=0;p<str.length();++p){
                if(!loop->chs[str[p]-'a']) loop->chs[str[p]-'a'] = new TrieNode;
                loop = loop->chs[str[p]-'a'];
            }
            loop->used = true;
        }
        TrieNode *loop = root;
        while(true){
            if(loop->used) break;
            int cnt = 0;
            char ch;
            for(int i=0;i<26;++i){
                if(loop->chs[i]){
                    ch = i + 'a';
                    cnt++;
                }
            }
            if(cnt == 1){
                loop = loop->chs[ch-'a'];
                result += ch;
            }else break;
        }
        return result;
    }
};

int main(int argc,char *argv[]){
    vector<string> str{"dog","racecar","car"};
    vector<string> str1{"a","aa"};
    vector<string> str2{"","bb"};
    Solution s;
    cout << s.longestCommonPrefix(str2);
    return 0;
}
