#include <bits/stdc++.h>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int searchLeft(int target, MountainArray &arr, int l, int count) {
    int r = l + count;
    while(count > 0) {
      int step = count / 2;
      int mid = l + step;
      if(arr.get(mid) < target) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    if(l >= r) { return -1; }
    return arr.get(l) == target ? l : -1;
  }

  int searchRight(int target, MountainArray &arr, int l, int count) {
    int r = l + count;
    while(count > 0) {
      int step = count / 2;
      int mid = l + step;
      if(arr.get(mid) > target) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    if(l >= r) { return -1; }
    return arr.get(l) == target ? l : -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    int l = 0;
    int count = mountainArr.length();
    while(count > 0) {
      int step = count / 2;
      int mid = l + step;
      // 1 2 3 5 3
      if(mid + 1 < mountainArr.length() && mountainArr.get(mid) <= mountainArr.get(mid + 1)) {
        l = mid + 1;
        count -= step + 1;
      }else {
        count = step;
      }
    }
    int split = l;
    l = searchLeft(target, mountainArr, 0, split);
    if(l != -1) { return l; }
    l = searchRight(target, mountainArr, split, mountainArr.length() - split);
    return l;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
