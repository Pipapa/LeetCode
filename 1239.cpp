#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool calc(const string& str, int& ret) {
    ret = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
      int m = 1 << (str[i] - 'a');
      if(m & ret) { return false; }
      ret = m | ret;
    }
    return true;
  }

  int one(int m) {
    int ret = 0;
    while(m) {
      if(m & 0x1) { ++ret; }
      m = m >> 1;
    }
    return ret;
  }

  int maxLength(vector<string>& arr) {
    vector<int> mask;
    for(string& str : arr) {
      int m = 0;
      if(calc(str, m)) {
        mask.push_back(m);
      }
    }
    int ret = 0;
    for(int i = 1; i < (1 << mask.size()); ++i) {
      int b = i, t = 0, m = 0;
      while(b) {
        if(b & 1) {
          if(m & mask[t]) {
            break;
          }
          m = m | mask[t];
        }
        b = b >> 1;
        ++t;
      }
      ret = max(ret, one(m));
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
