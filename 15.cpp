#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // [l..r] find target
    int find(vector<int>& arr,int l,int r,int target){
        while(l <= r){
            int mid = (l+r)/2;
            if(arr[mid] > target){
                r = mid-1;
            }else if(arr[mid] < target){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size() - 1;
        if(len == 0 || len < 2 )
            return result;
        sort(nums.begin(),nums.end());
        int l = 0;
        while(l <= len-2){
           int r = len;
           while(r >= l+1){
               int need = - (nums[l] + nums[r]);
               if(need > nums[r]) break;
               if(need >= nums[l]){
                   int pos = find(nums,l+1,r-1,need);
                   if(pos != -1){
                       result.push_back(vector<int>{nums[l],nums[pos],nums[r]});
                   }
               }
               // 排重
               while(r >= l+1 && nums[r-1] == nums[r]) r--;
               r--;
           }
           // 排重
           while(l <= len-2 && nums[l] == nums[l+1]) l++;
           l++;
        }
        return result;
    }
};


int main(int argc,char *argv[]){
    vector<int> test0{-2,0,1,1,2};
    vector<int> test1{-1, 0, 1, 2, -1, -4};
    vector<int> test2{0,0,0,0};
    vector<int> test3{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> test4{-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4};
    vector<int> test5{3,0,3,2,-4,0,-3,2,2,0,-1,-5};
    vector<int> test6{0,0,0};
    vector<vector<int>> test{test0,test1,test2,test3,test4,test5,test6};
    Solution s;
    s.threeSum(test6);
    for(vector<int> t : test){
        vector<vector<int>> ans = s.threeSum(t);
        for(vector<int> item : ans){
            for(int i : item){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "-------------" << endl;
    }

    return 0;
}