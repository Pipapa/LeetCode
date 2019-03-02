#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ,r = numbers.size() - 1;
        vector<int> result;
        while(l < r){
            int need = numbers[l] + numbers[r];
            if(need > target){
                r--;
            }else if(need < target){
                l++;
            }else{
                result.resize(2);
                result[0] = ++l;
                result[1] = ++r;
                return result;
            }
        }
        return result;
    }
};

int main(int argc,char *argv[]){
    return 0;
}
