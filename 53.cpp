#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result,sum;
        result = sum = nums[0];
        for(int i=1;i<nums.size();++i){
            if(sum < 0){
                sum = nums[i];
            }else{
                sum += nums[i];
            }
            result = max(result,sum);
        }
        return result;
    }
};