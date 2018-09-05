#include <iostream>
#include <string>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn]={0};

int minimumDeleteSum(string s1, string s2) {
    int len_s1=s1.size(),len_s2=s2.size();
    dp[0][0]=0;
    for(int i=1;i<=len_s1;i++) dp[i][0]=dp[i-1][0]+s1[i-1];
    for(int i=1;i<=len_s2;i++) dp[0][i]=dp[0][i-1]+s2[i-1];
    for(int i=1;i<=len_s1;i++){
        for(int j=1;j<=len_s2;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
        }
    }
    return dp[len_s1][len_s2];
}

int main(){
    return 0;
}