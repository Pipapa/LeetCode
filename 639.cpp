#include <iostream>
#include <string>
using namespace std;

const int maxn = 10010;
const int mod_num = 1000000007;
unsigned long dp[maxn]={0};
int numDecodings(string s) {
    if(s[0] == '0') return 0;
    int str_len = s.size();
    dp[0] = 1;
    dp[1] = s[0] == '*' ? 9:1;
    for(int i=2;s[i-1]!='\0';i++){
        if(s[i-1] == '0'){
            if(s[i-2] == '*') dp[i] = (dp[i-2] * 2)%mod_num;
            else if(s[i-2] > '2' || s[i-2] <= '0') return 0;
            else dp[i] = dp[i-2];
        }else if(s[i-1] == '*'){
            dp[i] = dp[i-1]*9;
            if(s[i-2] == '*') dp[i] = (dp[i] + dp[i-2]*15)%mod_num;
            else if(s[i-2] == '2') dp[i] = (dp[i] + dp[i-2]*6)%mod_num;
            else if(s[i-2] == '1') dp[i] = (dp[i] + dp[i-2]*9)%mod_num;
        }else if(s[i-2] == '1' || (s[i-2]=='2' && s[i-1] <='6')) dp[i] = (dp[i-1] + dp[i-2])%mod_num;
        else if(s[i-2] == '*'){
            if(s[i-1] >= '7') dp[i] = (dp[i-1] + dp[i-2])%mod_num;
            else dp[i] = (dp[i-1] + dp[i-2] * 2)%mod_num;
        }
        else dp[i] = dp[i-1];
    }
    return (int)(dp[str_len] % mod_num);
} 

int main(){
    cout << numDecodings("*********") << endl;
    return 0;
}