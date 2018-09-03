#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int dp[maxn][maxn] = {0};

int longestPalindromeSubseq(string s) {
    int m = s.size();
    for(int i=0;i<m;i++) dp[i][i]=1;
    for(int i=1;i<m;i++){
        for(int j=0;i+j<m;j++){
            if(s[j] == s[i+j]){
                if(i==1) dp[j][i+j] = 2;
                else dp[j][i+j] = 2 + dp[j+1][i+j-1];
            }else{
                dp[j][i+j] = max(dp[j][i+j-1],dp[j+1][i+j]);
            }
        }
    }
    return dp[0][m-1];
}


int main(){
    cout << longestPalindromeSubseq("cbbd") << endl;
    return 0;
}