#include <iostream>
#include <alogrithm>

int rob(vector<int>& nums) {
    int dp[10010]={0},len=nums.size();
    if(len>=1) dp[1]=nums[0];
    if(len>=2) dp[2]=max(nums[1],nums[0]);
    for(int i=3;i<=len;i++){
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }
    return dp[len];
}

int main(){
    return 0;
}