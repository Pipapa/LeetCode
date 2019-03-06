#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[1010][1010] = {false};
        int lens = s.length();
        int lenp = p.length();
        // init
        dp[0][0] = true;
        for(int is=1;is<=lens;++is) dp[is][0] = false;
        for(int ip=1;ip<=lenp;++ip){
            if(p[ip-1] == '*') dp[0][ip] = dp[0][ip-2];
            else dp[0][ip] = false;
        }
        for(int is=1;is<=lens;++is){
            for(int ip=1;ip<=lenp;++ip){
                if(p[ip-1] == s[is-1] || p[ip-1] == '.'){
                    dp[is][ip] = dp[is-1][ip-1];
                }else if(p[ip-1] == '*'){
                    if(p[ip-2] == '.' || p[ip-2] == s[is-1]){
                        dp[is][ip] = dp[is][ip-1] || dp[is][ip-2] || dp[is-1][ip];
                    }else dp[is][ip] = dp[is][ip-2];
                }else dp[is][ip] = false;
            }
        }
        return dp[lens][lenp];
    }
};



int main(int argc,char *argv[]){
    Solution s;
    //"mississippi"
    //"mis*is*p*."
    cout << s.isMatch("mississippi","mis*is*p*.") << endl;
    return 0;
}
