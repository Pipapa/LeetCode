#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
        int dp[110][110]={0};
        for(int i=1;i<=m;i++) dp[1][i]=1;
        for(int i=1;i<=n;i++) dp[i][1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
}

int main(){
    uniquePaths(7,3);
    return 0;
}