#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sL1 = nums1.size(), sL2 = nums2.size();
    int count = sL1 + sL2;
    int k = (count - 1) / 2;
    int iL1 = 0, iL2 = 0;
    while(k > 1) {
      if(iL1 == sL1) { iL2 += k; k = 0; break; }
      if(iL2 == sL2) { iL1 += k; k = 0; break; }
      int l1 = iL1 + k / 2 - 1;
      int l2 = iL2 + k / 2 - 1;
      if(l1 >= sL1) { l1 = sL1 - 1; }
      if(l2 >= sL2) { l2 = sL2 - 1; }
      if(nums1[l1] > nums2[l2]) {
        k -= l2 + 1 - iL2;
        iL2 = l2 + 1;
      }else {
        k -= l1 + 1 - iL1;
        iL1 = l1 + 1;
      }
    }
    double ret;
    if(k == 1) {
      if(iL1 == sL1) { ++iL2; }
      else if(iL2 == sL2) { ++iL1; }
      else if(nums1[iL1] < nums2[iL2]) { ++iL1; }
      else { ++iL2; }
    }
    if(iL1 == sL1) { ret = nums2[iL2++]; }
    else if(iL2 == sL2) { ret = nums1[iL1++]; }
    else if(nums1[iL1] < nums2[iL2]) { ret = nums1[iL1++]; }
    else { ret = nums2[iL2++]; }
    if(count & 1) { return ret; }
    if(iL1 == sL1) { ret = (ret + nums2[iL2]) / 2; }
    else if(iL2 == sL2) { ret = (ret + nums1[iL1]) / 2; }
    else if(nums1[iL1] < nums2[iL2]) { ret = (ret + nums1[iL1]) / 2; }
    else { ret = (ret + nums2[iL2]) / 2; }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
