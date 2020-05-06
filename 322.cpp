#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; ++i) {
      int m = INT_MAX;
      for(int k : coins) {
        if(i - k == 0){
          m = min(m, 1);
        }else if(i - k < 0) {
          m = min(m, INT_MAX);
        }else if(dp[i-k] != INT_MAX){
          m = min(m, dp[i-k] + 1);
        }
      }
      if(m != INT_MAX) {
        dp[i] = min(dp[i], m);
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
