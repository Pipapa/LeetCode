#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int ret = 0, sum = 0;
    unordered_map<int, int> hash;
    hash.insert({0, 1});
    for(int i : nums) {
      sum += i;
      if(hash.find(sum - k) != hash.end()) {
        ret += hash[sum - k];
      }
      if(hash.find(sum) != hash.end()) {
        hash[sum]++;
      }else {
        hash.insert({sum, 1});
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
