#include <iostream>
#include <string>
using namespace std;

const int maxn=10010;
int dp[maxn]={0};


/*

f(n) = f(n)
f(n) = f(n-1) + f(n-2)  可以结合时
f(n) = f(n-2)  为0时必然与前面结合
*/
int numDecodings(string s){
    if(s[0] == '0') return 0;
    int str_len = s.size();
    dp[1] = dp[0] = 1;
    for(int i=2;s[i-1]!='\0';i++){
        if(s[i-1] == '0'){
            if(s[i-2] > '2' || s[i-2] <= '0') return 0;
            dp[i] = dp[i-2];
        }else if(s[i-2] == '0'){
            dp[i] = dp[i-2];
        }else if( (s[i-2]=='2' && s[i-1] <= '6') || s[i-2]=='1'){
            dp[i] = dp[i-1] + dp[i-2];
        }else dp[i] = dp[i-1];
    }
    return dp[str_len];
}

int main(){
    cout <<numDecodings("17") << endl;
    return 0;
}