#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  // 1 2 3 4 5
  // f f t t t
  int firstBadVersion(int n) {
    int l = 1, count = n;
    while(count > 0) {
      int step = count / 2;
      int mid  = l + step;
      if(!isBadVersion(mid)) {
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
