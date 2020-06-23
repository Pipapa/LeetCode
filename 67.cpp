#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len_a = a.size();
    int len_b = b.size();
    int max_len = max(len_a, len_b);
    int tmp = 0;
    string ans = "";
    for(int i = 0; i < max_len; ++i) {
      int iA = 0, iB = 0;
      if(i >= len_a) { iA = 0; }
      else { iA = a[i] - '0'; }
      if(i >= len_b) { iB = 0;}
      else { iB = b[i] - '0'; }
      int t = tmp + iA + iB;
      if(t < 2) {
        tmp = 0;
        ans = string(1, t + '0') + ans;
      }else {
        tmp = 1;
        ans = string(1, t - 2 + '0') + ans;
      }
    }
    if(tmp) { ans = '1' + ans; }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
