#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool NextPremutation(vector<int>::iterator first, vector<int>::iterator last) {
    if(first == last) return false;
    auto i = last;
    if(first == --i) return false;
    while(true) {
      auto ii = i;
      if(*--i < *ii) {
        auto j = last;
        while(!(*i < *--j)) {}
        iter_swap(i, j);
        reverse(ii, last);
      }
      if(i == first) {
        return false;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    do {
      ret.push_back(nums);
    }while(NextPremutation(nums.begin(), nums.end()));
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
