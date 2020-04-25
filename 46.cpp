#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void dfs(vector<int>& nums, int dep, vector<vector<int>>& ret) {
    if(dep == nums.size()) {
      ret.push_back(nums);
    }else {
      for(int i = dep; i < nums.size(); ++i) {
        swap(nums[i], nums[dep]);
        dfs(nums, dep + 1, ret);
        swap(nums[i], nums[dep]);
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    dfs(nums, 0, ret);
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
