#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(target == nums[mid]) return mid;
            if(target > nums[r] && nums[mid] <= nums[r]) r = mid - 1;
            else if(target < nums[l] && nums[mid] >= nums[l]) l = mid + 1;
            else{
                if(target > nums[mid]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};


int main(int argc,char *argv[]){
    Solution s;
    return 0;
}
