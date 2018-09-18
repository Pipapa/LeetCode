#include <iostream>
#include <vector>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    int len_a = A.size(),len_b = B.size();
    int ans = 0;
    vector<vector<int>> dp(len_a+1,vector<int>(len_b+1,0));
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            if(A[i-1] == B[j-1]) {
                if(A[i-2] == B[j-2] && i>=2 && j>=2) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 1;
            }
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main(){
    return 0;
}