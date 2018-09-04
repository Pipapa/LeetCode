#include <iostream>
#include <algorithm>
using namespace std;

int climbStairs(int n) {
    int dp[10100]={0};
    dp[1]=1,dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    return 0;
}