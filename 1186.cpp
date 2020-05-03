#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumSum(vector<int>& arr) {
    size_t len = arr.size();
    int ret = INT_MIN;

    vector<int> l2r(len, 0);
    vector<int> r2l(len + 2, 0);

    l2r[0] = arr[0];
    for(int i = 1; i < len; ++i) {
      l2r[i] = max(arr[i], l2r[i-1]+arr[i]);
    }

    r2l[len] = r2l[len+1] = 0;
    r2l[len - 1] = arr[len - 1];
    for(int i = len - 2; i >= 0 ; --i) {
      r2l[i] = max(arr[i], r2l[i+1]+arr[i]);
    }

    for(int i = 0; i < len; ++i) {
      ret = max(ret, l2r[i] + max(r2l[i+1],r2l[i+2]));
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  vector<int> kase={1,-2,0,3};
  Solution s;
  assert(1 == 1);
  s.maximumSum(kase);
  return 0;
}
