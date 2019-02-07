#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    struct TrieNode{
        TrieNode* chs[26];
        bool used;
        unsigned pos;
        TrieNode():used(false),pos(0){
            for(int i=0;i<26;i++){chs[i]=NULL;}
        }
    };
    TrieNode *root;
    // loop test
    stack<TrieNode*> stack_node;
    stack<string> stack_str;

    bool IsPalindrome(string &str,int l,int r){ // [l,r]
        while(l < r){if(str[l++]!=str[r--]) return false;}
        return true;
    }

    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        root = new TrieNode();
        for(int ps=0;ps<words.size();++ps){
            string str = words[ps];
            TrieNode *loop = root;
            for(int i=str.length()-1;i>=0;--i){
                if(loop->chs[str[i]-'a'] == NULL) loop->chs[str[i]-'a'] = new TrieNode();
                loop = loop->chs[str[i]-'a'];
            }
            loop->used = true;
            loop->pos = ps;
        }
        // find each word palindrome
        for(int ps=0;ps<words.size();++ps){
            int pos = 0;
            vector<int> pn = find(words[ps]);
            for(int i=0;i<pn.size();++i) {
                int arr[2] = {ps, pn[i]};
                if (arr[0] != arr[1])
                    ans.push_back(vector<int>(arr, arr + 2));
            }
        }
        return ans;
    }


    // get the all can match pair
    vector<int> find(string& str){
        TrieNode *loop = root;
        vector<int> ans;
        int len = str.length();
        for(int i=0;i<len;++i){
            if(loop->used){
                if(IsPalindrome(str,i,len-1))
                    ans.push_back(loop->pos);
            }
            if(loop->chs[str[i]-'a'] == NULL){
                return ans;
            }
            loop = loop->chs[str[i]-'a'];
        }
        while (!stack_node.empty()) stack_node.pop();
        while (!stack_str.empty()) stack_str.pop();
        stack_node.push(loop);
        stack_str.push("");
        while (!stack_node.empty()){
            TrieNode *tmp = stack_node.top();stack_node.pop();
            string tmp_s = stack_str.top();stack_str.pop();
            if(tmp->used){
                //judge the tmp_s is palindrome
                if(IsPalindrome(tmp_s,0,tmp_s.length()-1)) ans.push_back(tmp->pos);
            }
            for(int i=0;i<26;i++){
                if(tmp->chs[i]){
                    stack_node.push(tmp->chs[i]);
                    stack_str.push(tmp_s+char(i+'a'));
                }
            }
        }
        return ans;
    }
};

int main(){
//    string arr[] = {"a",""};
//string arr[] = {"a","b","c","ab","ac","aa"};
//string arr[] = {"abcd","dcba","lls","s","sssll"};
string arr[] = {"bat","tab","cat"};
    vector<string> test(arr,arr+3);
    Solution s;
    vector<vector<int> >ans = s.palindromePairs(test);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}