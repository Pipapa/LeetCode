#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int Op(char c, int i, int j) {
    switch(c) {
      case '+':
        return i + j;
      case '-':
        return i - j;
      case '*':
        return i * j;
    }
    return 0;
  }

  vector<int> calc(const string& str, int l, int r) {
    vector<int> ret;
    bool flag = true;

    for(int i = l; i <= r; ++i) {
      if(str[i] == '*' || str[i] == '+' || str[i] == '-') {
        flag = false;
        auto retL = calc(str, l, i-1);
        auto retR = calc(str, i+1, r);
        for(int k = 0; k < retL.size(); ++k) {
          for(int j = 0; j < retR.size(); ++j) {
            ret.push_back(Op(str[i], retL[k], retR[j]));
          }
        }
      }
    }

    if(flag) {
      int cnt = 0;
      for(;l <= r; ++l) {
        cnt = cnt * 10 + str[l] - '0';
      }
      ret.push_back(cnt);
    }
    return ret;
  }

  vector<int> diffWaysToCompute(string input) {
    auto ret = calc(input, 0, input.size() - 1);
    sort(ret.begin(), ret.end());
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  for(auto i : s.diffWaysToCompute("2*3-4*5")) {
    cout << i << " ";
  }
  return 0;
}
