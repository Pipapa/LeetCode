#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
      int l = 0;
      int count = citations.size();
      int len   = count;
      while(count > 0) {
        int step = count / 2;
        int mid  = l + step;
        if(len - mid > citations[mid]) {
          l = mid + 1;
          count -= step + 1;
        }else {
          count = step;
        }
      }
      return len - l;
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
