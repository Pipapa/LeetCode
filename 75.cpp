#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums){
    int s_0=0,e_2=nums.size()-1,i=0;
    while(i<=e_2){
        if(nums[i]==0){swap(nums[s_0++],nums[i++]);}
        else if(nums[i]==2){swap(nums[e_2--],nums[i]);}
        else i++;
    }
}

int main(){
    return 0;
}