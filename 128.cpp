#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_nums(nums.begin(),nums.end());
        int ret = 0;
        for(int i : set_nums){
            if(!set_nums.count(i-1)){
                int cnt = 0;
                while (set_nums.count(i+cnt)) cnt++;
                ret = max(ret,cnt);
            }
        }
        return ret;
    }
};

int main(){
    vector<int> test{1,2,0,1};
    Solution s;
    s.longestConsecutive(test);
    return 0;
}
