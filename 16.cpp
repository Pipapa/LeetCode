#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums,int l_,int r_,int target){
        int l = l_, r = r_;
        int ret = 0, ans = INT_MAX;
        int mid = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(target == nums[mid]) return target;
            else if(target > nums[mid]) l = mid + 1;
            else r = mid - 1;
        }
        if(l >= l_ && l <= r_ && abs(target-nums[l]) < ans) {
            ans = abs(target-nums[l]);
            ret = nums[l];
        }
        if(r >= l_ && r <= r_ && abs(target-nums[r]) < ans) {
            ans = abs(target-nums[r]);
            ret = nums[r];
        }
        if(mid >= l_ && mid <= r_ && abs(target-nums[mid]) < ans) {
            ans = abs(target-nums[mid]);
            ret = nums[mid];
        }
        return ret;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int ret = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int l = 0; l <= r-2; ++l) {
            for(int i = r; i >= l+2; --i) {
                int toFind = target - nums[l] - nums[i];
                if(toFind <= nums[l] && l > 0) {
                   if(abs(nums[l-1]-toFind) <= ret) {
                       ret = abs(nums[l-1] - toFind);
                       ans = nums[l-1] + nums[i] + nums[l];
                   }
                   if(ret == 0) return ans;
                }
                if(toFind >= nums[i] && i < r) {
                    if(abs(nums[i+1]-toFind) <= ret) {
                        ret = abs(nums[i+1] - toFind);
                        ans = nums[i+1] + nums[l] + nums[i];
                    }
                    if(ret == 0) return ans;
                }
                int searchNum = search(nums, l+1, i-1, toFind);
                if(abs(searchNum-toFind) <= ret) {
                    ret = abs(searchNum-toFind);
                    ans = nums[l] + nums[i] + searchNum;
                }
                if(ret == 0) return ans;
                if(toFind > nums[i]) break;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,4,8,16,32,64,128};
    Solution s;
    std::cout << s.threeSumClosest(arr, 82) << std::endl;
    return 0;
}
