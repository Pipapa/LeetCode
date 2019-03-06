class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        int len = nums.size();
        for(int i=1;i<len;++i){
            result ^= nums[i];
        }
        return result;
    }
};
