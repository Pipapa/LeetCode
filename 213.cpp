#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    vector<int> dpf(nums.begin(), nums.end());
    vector<int> dpl(nums.begin(), nums.end());
    int len = nums.size();
    if(len == 0) { return 0; }
    if(len == 1) { return nums[0]; }
    if(len == 2) { return max(nums[0], nums[1]); }
    dpf[1] = max(dpf[0], dpf[1]);
    dpf[2] = max(dpf[1], dpf[0] + nums[2]);
    dpl[2] = max(dpl[1], dpl[2]);
    for(int i = 3; i < len; ++i) {
      dpf[i] = max(dpf[i-1], dpf[i-2]+nums[i]);
      dpl[i] = max(dpl[i-1], dpl[i-2]+nums[i]);
    }
    return max(dpf[len-2], dpl[len-1]);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
