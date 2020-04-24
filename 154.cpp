#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int count = nums.size();
    int r = count - 1;
    int l = 0;
    int it = 0;
    while(count > 0) {
      int step = count / 2;
      int mid = it + step;
      if(nums[l] < nums[r]) {
        return nums[l];
      }else if(mid > 0 && nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }else if(nums[mid] == nums[l]) {
        if(it == l && it < r - 1) {
          ++it;
        }
        --count;
        ++l;
      }else if(nums[mid] > nums[l]) {
        it = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    return nums[it];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> kase{2,2,2,0,1};
  assert(1 == 1);
  assert(s.findMin(kase) == 0);
  return 0;
}
