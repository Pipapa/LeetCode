#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> singleNumbers(vector<int>& nums) {
    vector<int> ret(2, 0);
    int cnt = 0;
    bitset<10010> b;
    for(int i : nums) {
      if(b[i]) b[i] = 0;
      else b[i] = 1;
    }
    for(int i : nums) {
      if(b[i]) {
        ret[cnt++] = i;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
