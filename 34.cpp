class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int count = nums.size();
        int l = 0;
        if(count == 0) {
            return vector<int>{-1, -1};
        }
        while(count > 0) {
            int step = count >> 1;
            int mid = l + step;
            if(nums[mid] <= target) {
                l = mid + 1;
                count -= step + 1;
            }else {
                count = step;
            }
        }
        if((l == 0 && nums[l] != target) || nums[l-1] != target) {
            return vector<int>{-1, -1};
        }
        if(l == 0) {
            return vector<int>{0, 0};
        }
        --l;
        int r = l;
        for(; l > 0 && nums[r] == nums[l]; --l);
        if(nums[l] != nums[r]) ++l;
        return vector<int>{l, r};
    }
};
