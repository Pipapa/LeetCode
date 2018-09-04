#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int dp[1010] = {0};
    int len = cost.size();
    dp[0]=dp[1]=0;
    for(int i=2;i<=len;i++){
        dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
    }
    return dp[len];
}

int main(){
    return 0;
}