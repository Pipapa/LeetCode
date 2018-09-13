#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if(i >=nums[j]){ dp[i] += (dp[i-nums[j]]);}
        }
    }
    return dp[target];
}

int main(){
    int a[] = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    return 0;
}