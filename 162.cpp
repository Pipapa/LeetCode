#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int count = nums.size();
        int l = 0;
        while(count > 0) {
            int step = count / 2;
            int mid = l + step;
            if(mid + 1 < nums.size() && nums[mid] <= nums[mid + 1]) {
                l = mid + 1;
                count -= step + 1;
            }else {
                count = step;
            }
        }
        return l;
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
