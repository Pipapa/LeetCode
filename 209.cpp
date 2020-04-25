#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0, r = 1;
    if(nums.size() < 1) {
      return 0;
    }
    int sum = nums[0];
    int minLen = INT_MAX;
    while( true ) {
      if(sum < s) {
        if(r >= nums.size()) {
          break;
        }
        sum += nums[r++];
      }else {
        if(r - l < minLen) {
          minLen = r - l;
        }
        sum -= nums[l++];
      }
    }
    return minLen == INT_MAX ? 0 : minLen;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
