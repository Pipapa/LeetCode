#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int it = 0, l = 0, r = nums.size() - 1;
    int count = nums.size();
    while(count > 0) {
      int step = count / 2;
      int mid = it + step;
      if(nums[mid] == target) {
        return true;
      }else if(nums[mid] == nums[r] && l < r - 1) {
        --r;
        --count;
      }else if(nums[mid] > target) {
        if(nums[mid] < nums[l] || target >= nums[l]) {
          count = step;
        }else {
          it = mid + 1;
          count -= step + 1;
        }
      }else {
        if(nums[mid] >= nums[l] || target < nums[l]) {
          it = mid + 1;
          count -= step + 1;
        }else {
          count = step;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(1 == 1);
    return 0;
}
