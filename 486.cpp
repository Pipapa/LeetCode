#include <iostream>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int>& nums) {
    int len = nums.size();
    int dp[20][20] = {0};
    for(int i=0;i<len;i++){dp[i][i]=nums[i];}
    for(int k=1;k<len;k++){
        for(int i=0;i+k<len;i++){
            dp[i][i+k] = max(nums[i]-dp[i+1][i+k],nums[i+k]-dp[i][i+k-1]);
        }
    }
    return dp[0][len-1]>=0;
}

int main(){
    return 0;
}