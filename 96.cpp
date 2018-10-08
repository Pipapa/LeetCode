#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            dp[i] += (dp[j]*dp[i-1-j]);
        }
    }
    return dp[n];
}

int main(){
    cout << numTrees(19) << endl;
    return 0;
}
