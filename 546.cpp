#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int solve(vector<int>& boxes, int l, int r, int k) {
        if(l > r) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k];
        int ret = (k+1)*(k+1) + solve(boxes, l+1, j, 0);
        for(int i = l+1; i <= r; ++i) {
            if(boxes[i] == boxes[l]) {
                ret = max(ret, solve(boxes, l+1, i-1, 0) + solve(boxes, i, j, k+1));
            }
        }
        return ret;
    }

    int removeBoxes(vector<int>& boxes) {
        return(boxes, 0, boxes.size()-1, 0);                             
    }
};

int main() {
    vector<int> boxes;
    Solution s;
    s.removeBoxes(boxes);
    return 0;
}
