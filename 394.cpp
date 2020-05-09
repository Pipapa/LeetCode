#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    stack<string> sStr;
    stack<int> sSum;
    while(s[i]!='\0') {
      if(s[i] == ']') {
        string istr = "";
        string nstr = "";
        while(sStr.top() != "[") {
          istr = sStr.top() + istr;
          sStr.pop();
        }
        sStr.pop();
        int cnt = sSum.top(); sSum.pop();
        for(int i = 0; i < cnt; ++i) {
          nstr = nstr + istr;
        }
        sStr.push(nstr);
        ++i;
      }else if(s[i] >= '0' && s[i] <= '9') {
        int n = 0;
        while(s[i] >= '0' && s[i] <= '9') {
          n = n * 10 + (s[i] - '0');
          ++i;
        }
        sSum.push(n);
      }else {
        string str(1, s[i]);
        sStr.push(str);
        ++i;
      }
    }
    string ret = "";
    while(!sStr.empty()) {
      ret = sStr.top() + ret;
      sStr.pop();
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  std::cout << s.decodeString("3[a]2[bc]") << std::endl;
  return 0;
}
