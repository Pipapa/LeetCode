#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class WordFilter {
private:
    struct TrieNode{
        TrieNode *chs[27];
        int used;
        // {
        TrieNode():used(-1){
            for(int i=0;i<27;i++){chs[i] = NULL;}
        }
    };
    TrieNode *root;
public:

    WordFilter(vector<string> words) {
        root = new TrieNode();
        // k*len^2
        for(int cnt=0;cnt<words.size();++cnt){
            for(int l=0;l<=words[cnt].length();++l){
                string str = words[cnt].substr(l) + '{' + words[cnt];
                bool flag = false;
                TrieNode *loop = root;
                for(int i=0;str[i]!='\0';++i){
                    if(!loop->chs[str[i]-'a']) loop->chs[str[i]-'a'] = new TrieNode();
                    loop = loop->chs[str[i]-'a'];
                    if(str[i] == '{') flag = true;
                    if(flag) loop->used = cnt;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string sstr =  suffix + '{' + prefix;
        TrieNode *loop = root;
        for(int i=0;sstr[i]!='\0';++i){
            if(!loop->chs[sstr[i]-'a']) return -1;
            loop = loop->chs[sstr[i]-'a'];
        }
        return loop->used;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */


int main(int argc,char *argv[]){
    vector<string> words{"abbbababbb","baaabbabbb","abababbaaa","abbbbbbbba","bbbaabbbaa",
                         "ababbaabaa","baaaaabbbb","babbabbabb","ababaababb","bbabbababa"};
    WordFilter *obj = new WordFilter(words);
    cout << obj->f("","abaa") << endl;
    cout << obj->f("babbab","") << endl;
    return 0;
}