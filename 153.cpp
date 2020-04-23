#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int count = nums.size();
    while(count > 0) {
      int step = count / 2;
      int mid = l + step;
      if(nums[mid] > nums[nums.size() - 1]) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    return nums[l];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
