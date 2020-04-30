#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int calc(vector<int>& w, int m) {
    int ret = 0, cnt = 0;
    for(int i : w) {
      if(cnt + i > m) {
        cnt = i;
        ++ret;
      }else {
        cnt += i;
      }
    }
    return ret + 1;
  }

  int shipWithinDays(vector<int>& weights, int D) {
    int l = INT_MIN;
    int count = 0;
    for(int k : weights) {
      count += k;
      l = max(l, k);
    }

    while(count > 0) {
      int step = count / 2;
      int mid  = l + step;
      if(calc(weights, mid) > D) {
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
  vector<int> kase{1,2,3,1,1};
  assert(1 == 1);
  cout << s.calc(kase, 2) << endl;
  cout << s.calc(kase, 3) << endl;
  return 0;
}
