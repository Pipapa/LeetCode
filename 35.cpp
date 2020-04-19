class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, count = nums.size();
        while(count > 0) {
            int step = count / 2;
            int mid = l + step;
            if(nums[mid] < target) {
                l = mid + 1;
                count -= step + 1;
            }else { // >=
                count = step;
            }
        }
        return l;
    }
};
