#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  /*
   * 7 5 6 4 [0, 4)
   * [0, 2) 7 5
   * [2, 4) 6 4
   * 5 7 4 6
   * 1 + 1 + 2 + 1
   * */
  int mergesort(vector<int>& nums, int l, int r) {
    int mid = (l + r) / 2;
    int m = mid;
    int ret = 0;
    if(r - l <= 1) {
      return 0;
    }
    ret += mergesort(nums, l, mid);
    ret += mergesort(nums, mid, r);
    vector<int> tmp(r - l, 0);
    int cnt = 0;
    while(l < mid && m < r) {
      if(nums[l] > nums[m]) {
        tmp[cnt++] = nums[m++];
        ret += mid - l;
      }else {
        tmp[cnt++] = nums[l++];
      }
    }
    while(l < mid) {
      tmp[cnt++] = nums[l++];
    }
    while(m < r) {
      tmp[cnt++] = nums[m++];
    }
    for(size_t i = 0; i < cnt; ++i) {
      nums[r - cnt + i] = tmp[i];
    }
    return ret;
  }

  int reversePairs(vector<int>& nums) {
    return mergesort(nums, 0, nums.size());
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> kase{7,5,6,4};
  assert(1 == 1);
  assert(s.reversePairs(kase) == 5);
  return 0;
}
