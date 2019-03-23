#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> table;
        map<int,int>::iterator it;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
                it = table.find(target-nums[i]);
                if(it != table.end()){
                        ans.push_back(it->second);
                        ans.push_back(i);
                        return ans;
                }
                table.insert({nums[i],i});
        }
        return ans;
    }
};
