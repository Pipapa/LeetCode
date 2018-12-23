#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char parr[128]={0};
    bool vis[26]={0};
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int len = pattern.length();
        for(string str:words){
            if(str.length() != len) continue;
            for(int i=0;i<128;i++){parr[i]=0;}
            for(int i=0;i<26;i++){vis[i]=false;}
            int flag=0;
            for(int i=0;i<str.length();i++){
                if(!parr[pattern[i]] && !vis[str[i]-'a']){
                    parr[pattern[i]]=str[i];
                    vis[str[i]-'a']=true;
                }else if(parr[pattern[i]]!=str[i]){
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            ans.push_back(str);
        }
        return ans;
    }
};

int main(){
    string arr[] = {"abc","deq","mee","aqq","dkd","ccc"};
    vector<string> test(arr,arr+5);
    Solution s;
    s.findAndReplacePattern(test,"abb");
    return 0;
}