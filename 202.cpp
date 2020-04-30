#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  inline int calc(int n) {
    int ret = 0;
    while(n) {
      ret += (n % 10) * (n % 10);
      n /= 10;
    }
    return ret;
  }
  bool isHappy(int n) {
    int l = n, f = n;
    l = calc(n);
    f = calc(calc(n));
    for(; ; l = calc(l), f = calc(calc(f))) {
      if(l == 1 || f == 1) { return true; }
      if(l == f) { return false; }
    }
    return l == 1 || f == 1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  s.isHappy(19);
  return 0;
}
