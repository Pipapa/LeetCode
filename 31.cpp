#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    auto first = nums.begin(), last = nums.end();
    if(first == last) return;
    auto i = last;
    if(first == --i) return;
    while(true) {
      auto ii = i;
      if(*--i < *ii) {
        auto j = last;
        while(!(*i < *--j)) {}
        iter_swap(i, j);
        reverse(ii, last);
        return;
      }
      if(i == first) {
        reverse(first, last);
        return;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
