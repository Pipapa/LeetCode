#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
      if(c == '[' || c == '{' || c == '(') {
        st.push(c);
      }else {
        if(st.empty()) return false;
        else if(c == ']' && st.top() != '[') return false;
        else if(c == '}' && st.top() != '{') return false;
        else if(c == ')' && st.top() != '(') return false;
        else st.pop();
      }
    }
    return st.empty();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
