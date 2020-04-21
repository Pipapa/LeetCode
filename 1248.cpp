#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ret = 0;
        vector<size_t> odds;
        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] & 1) {
                odds.push_back(i);
            }
        }
        if(odds.size() < k) {
            return 0;
        }
        // [l, r]
        for(size_t r = k - 1, l = 0; r < odds.size(); ++r, ++l) {
            size_t left = 0, right = 0;
            left  = (l == 0 ? odds[l] + 1 : odds[l] - odds[l-1]);
            right = (r == odds.size() - 1 ? nums.size() - odds[r] : odds[r + 1] - odds[r]);
            ret += left * right;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> kase{1,1,2,1,1};
    assert(1 == 1);
    assert(s.numberOfSubarrays(kase, 3) == 2);
    return 0;
}
