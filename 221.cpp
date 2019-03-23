#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp;
        dp.resize(r);
        for(int i=0;i<r;++i){
            dp[i].resize(c);
            for(int j=0;j<c;++j){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    ret = 1;
                }
                else dp[i][j] = 0;
            }
        }
        for(int i=1;i<r;++i){
            for(int j=1;j<c;++j){
                if(matrix[i][j] == '0') continue;
                if(matrix[i-1][j-1] == '0') continue;
                int s = dp[i-1][j-1];
                int flag = true;
                int slen = 0;
                for(int k=1;k<=s;++k){
                    if(matrix[i-k][j] == '0') {flag=false;break;}
                    if(matrix[i][j-k] == '0') {flag=false;break;}
                    slen++;
                }
                if(!flag && slen==0) continue;
                if(!flag) dp[i][j] = slen+1;
                else dp[i][j] = (dp[i-1][j-1]+1);
                ret = max(ret,dp[i][j]);
            }
        }
        return ret*ret;
    }
};

int main(){
    vector<vector<char>> test{
        {'0','0','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
        {'0','1','1','1'},
        {'0','1','1','1'}
    };
    Solution s;
    cout << s.maximalSquare(test) << endl;
    return 0;
}
