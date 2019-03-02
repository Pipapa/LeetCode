#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        0 - 0
        1 - 0 1
        2 - 0 1 2
        3 - 0 1 2 3
        4 - 0 1 2 3 4
        15 10 13

        tmp = 10
        pre = 11
        dp[i][j] = min(dp[i-1][j-1] , dp[i-1][j])
        dp[j] = min(dp[j-1] , t) + arr[j];
        t = dp[j];
        */
        int result = 0,pre = 0;
        int level = triangle.size();
        if(level == 0) return 0;
        vector<int> dp(level,0);

        pre = dp[0] = result = triangle[0][0];
        for(int row=1;row<triangle.size();++row){
            for(int col=0;col<=row;++col){
                if(col == 0){
                    pre = dp[0];
                    dp[0] += triangle[row][col];
                    result = dp[0];
                }else if(col == row){
                    dp[col] = pre + triangle[row][col];
                    result = min(result,dp[col]);
                }else{
                    int tmp = dp[col];
                    dp[col] = min(dp[col],pre) + triangle[row][col];
                    pre = tmp;
                    result = min(result,dp[col]);
                }
            }
        }
        return result;
    }
};

int main(int argc,char *argv[]){
    return 0;
}
