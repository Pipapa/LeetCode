#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    vector<vector<int>> dp = matrix;
    int ret = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i = 0; i < row; ++i) { ret += matrix[i][0]; }
    for(int i = 1; i < col; ++i) { ret += matrix[0][i]; }
    for(int r = 1; r < row; ++r) {
      for(int c = 1; c < col; ++c) {
        if(!dp[r][c]) { continue; }
        dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
        ret += dp[r][c];
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
