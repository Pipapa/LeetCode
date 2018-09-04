#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        dp.push_back(0);
        for(int num:nums) dp.push_back(dp.back()+num);
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
private:
    vector<int> dp;
};

int main(){
    return 0;
}