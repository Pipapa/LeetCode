#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findTargetSumWays(vector<int>& nums, int S) {
    int dp[22][4444] = {0};
    dp[0][2000-nums[0]] = 1;
    dp[0][2000+nums[0]] += 1; // + - 0 statu
    for(int i=1;i<nums.size();i++){
        for(int cnt=1000;cnt<=3000;cnt++){
            dp[i][cnt] = dp[i-1][cnt-nums[i]] + dp[i-1][cnt+nums[i]]; 
        }
    }
    return S>1000?0:dp[nums.size()-1][2000+S];

}

int main(){
    return 0;
}