#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool search(const vector<vector<int>>& matrix, int target, int rl, int rr, int cl, int cr) {
    int l, count;

    l = cl, count = cr - cl;
    while(count > 0) {
      int step = count / 2;
      int mid  = l + step;
      if(matrix[rl][mid] < target) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    if(l < cr && matrix[rl][l] == target) { return true; }
    cr = l;
    if(cl + 1 > cr) { return false; }

    l = rl, count = rr - rl;
    while(count > 0) {
      int step = count / 2;
      int mid  = l + step;
      if(matrix[mid][cr - 1] < target) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    if(l < rr && matrix[l][cr - 1] == target) { return true; }
    rl = l;
    if(rl + 1 > rr) { return false; }
    
    return search(matrix, target, rl, rr, cl, cr);
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) { return false; }
    return search(matrix, target, 0, matrix.size(), 0, matrix[0].size());
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
