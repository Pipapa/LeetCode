#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.size() == 0) { return 0; }
    if(obstacleGrid[0].size() == 0) { return 0; }
    int r = obstacleGrid.size();
    int c = obstacleGrid[0].size();
    vector<vector<int>> dp(r, std::vector<int>(c, 0));
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for(int i = 1; i < c; ++i) {
      dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i-1];
    }
    for(int i = 1; i < r; ++i) {
      dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
    }
    for(int i = 1; i < r; ++i) {
      for(int j = 1; j < c; ++j) {
        dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[r-1][c-1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
