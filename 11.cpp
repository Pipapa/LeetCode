#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ret = 0;
        while(l < r){
            ret = max(ret,(r-l)*(min(height[l],height[r])));
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return ret;
    }
};

int main(){
    return 0;
}
