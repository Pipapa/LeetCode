#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int r = dungeon.size();
    int c = dungeon[0].size();

    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[r - 1][c - 1] = max(1, 1 - dungeon[r - 1][c - 1]);

    for(int i = r - 2; i >= 0; --i) {
      dp[i][c - 1] = max(1, dp[i + 1][c - 1] - dungeon[i][c - 1]);
    }

    for(int i = c - 2; i >= 0; --i) {
      dp[r - 1][i] = max(1, dp[r - 1][i + 1] - dungeon[r - 1][i]);
    }

    for(int i = r - 2; i >= 0; --i) {
      for(int j = c - 2; j >=0; --j) {
        dp[i][j] = min(max(1, dp[i][j + 1] - dungeon[i][j]),
                       max(1, dp[i + 1][j] - dungeon[i][j]));
      }
    }
    return dp[0][0];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
