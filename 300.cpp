#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    /*
    int len = nums.size(),ans=1;
    if(len==0) return 0;
    vector<int> dp(len+1,1);
    dp[0]=1;
    for(int i=1;i<len;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
            ans = max(ans,dp[i]);
        }
    }
    return ans;*/

    int len=nums.size(),dp_len=0;
    vector<int> dp;
    for(int i=0;i<len;i++){
        auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
        if(it==dp.end()){dp.push_back(nums[i]);dp_len++;}
        else *it = nums[i];
    }
    return dp_len;
}

int main(){
    return 0;
}