#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while(l < r) {
      char cl = s[l], cr = s[r];
      if(cl >= 'A' && cl <= 'Z') cl = cl - 'A' + 'a';
      if(cr >= 'A' && cr <= 'Z') cr = cr - 'A' + 'a';
      if(!((cl >= 'a' && cl <= 'z') || (cl >= '0' && cl <= '9'))) {++l;}
      else if(!((cr >= 'a' && cr <= 'z') || (cr >= '0' && cr <= '9'))) {--r;}
      else if(cr != cl) { return false; }
      else { ++l;--r; }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
