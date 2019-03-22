#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:



    void build(vector<int>& nums,int root,int limit){
        int son = root*2+1;
        while(son <= limit){
            if(son+1 <= limit && nums[son+1] > nums[son]) son++;
            if(nums[son] <= nums[root]) break;
            swap(nums[son],nums[root]);
            root = son;
            son = root*2+1;
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        int limit = nums.size()-1;
        for(int i=(limit+1)/2-1;i>=0;--i){
            build(nums,i,limit);
        }
        for(auto i : nums){
            cout << i << " ";
        }
        for(int i=0;i<k-1;++i){
            swap(nums[0],nums[limit]);
            limit--;
            build(nums,0,limit);
        }
        return nums[0];
    }
};

int main(){
    Solution s;
    vector<int> test{3,2,1,5,6,4};
    s.findKthLargest(test,2);
    return 0;
}
