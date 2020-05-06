#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(512, 0);
    int index = 0;
    for(int i = 1; i <= 365; ++i) {
      if(days[index] == i) {
        // day i 
        int prev = i - 1;
        dp[i] = dp[prev] + costs[0];
        prev = i - 7 >= 0 ? i - 7 : 0;
        dp[i] = min(dp[i], dp[prev] + costs[1]);
        prev = i - 30 >= 0 ? i - 30 : 0;
        dp[i] = min(dp[i], dp[prev] + costs[2]);
        if(index == days.size() - 1) {
          break;
        }
        ++index;
      }else {
        dp[i] = dp[i-1];
      }
    }
    return dp[days[index]];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
