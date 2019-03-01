#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> space;
    bool judge(const string& str,int l,int r){
        int len = r-l+1;
        if(len > 3) return false;
        if(len == 1) return true;
        if(len == 2 && str[l]!='0') return true;
        // [l..r].len = 3
        if(str[l] == '0') return false;
        if(str[l] < '2') return true;
        if(str[l] > '2') return false;
        // 2..
        if(str[l+1] < '5') return true;
        if(str[l+1] > '5') return false;
        // 25x
        if(str[l+2] > '5') return false;
        return true;
    }
    // s[l..r] 能否组成n个标准
    void search(int l,int r,int n,const string& s){
        if(r<l) return;
        if(n==1){
            if(judge(s,l,r)){
                string tmp = "";
                for(string str:space) {
                    tmp += str;
                    tmp += ".";
                }
                tmp += s.substr(l,r-l+1);
                result.push_back(tmp);
            }else{ return;}
        }
        for(int i=l;i<=r && i<l+3;++i){
            if(r-i<=3*(n-1) && judge(s,l,i)){
                space.push_back(s.substr(l,i-l+1)); //s[l,i]
                search(i+1,r,n-1,s);
                space.pop_back();
            }else{
                continue;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        space.clear();
        search(0,s.length()-1,4,s);
        return result;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    vector<string> ans(s.restoreIpAddresses("010010"));
    for(string str:ans){
        cout << str << endl;
    }
    return 0;
}