#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int cnts1[26] = {0};
    int hashstr(const string& str,int l,int r){
        int hash = 0;
        for(int i=l;i<=r;++i){
            hash = hash + (str[i]-'a');
        }
        return hash;
    }
    bool teststr(const string& str,int l,int r){
        int cnt[26]={0};
        for(int i=0;i<26;++i) cnt[i]=0;
        for(int i=l;i<=r;++i){
            cnt[str[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(cnt[i] != cnts1[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int lenp = s1.length();
        int len = s2.length();
        if(len < lenp) return false;
        int hash = hashstr(s1,0,lenp-1);
        for(int i=0;i<26;++i) cnts1[i]=0;
        for(int i=0;s1[i]!='\0';++i){
            cnts1[s1[i]-'a']++;
        }
        int cnt = hashstr(s2,0,0+lenp-1);
        for(int i=0;i+lenp-1<=len-1;++i){
            if(cnt == hash && teststr(s2,i,i+lenp-1)){
                return true;
            }
            if(i+lenp < len)
                cnt = cnt - (s2[i] - 'a') + (s2[i+lenp] - 'a');
        }
        return false;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    cout << s.checkInclusion("ab","eidbaooo") << endl;
    return 0;
}
