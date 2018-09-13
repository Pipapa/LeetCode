#include <iostream>
#incldue <vector>
#include <algorithm>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int cnt[20001]={0};
    int dp[20001]={0};
    for(int n:nums){ cnt[n]++;}
    dp[1] = cnt[1];
    for(int i=2;i<20001;i++){
        dp[i] = max(dp[i-1],dp[i-2]+i*cnt[i]);
    }
    return dp[20000];
}

int main(){
    return 0;
}