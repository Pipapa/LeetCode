#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int end = 0;
    int ret = 0;
    int r = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(i > end) {
        ++ret;
        end = r;
      }
      r = max(r, i + nums[i]);
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
