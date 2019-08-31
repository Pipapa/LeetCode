class Solution {
public:
    bool isMatch(string s, string p) {
        s = "$" + s;
        p = "$" + p;
        int len_s = s.length();
        int len_p = p.length();
        vector<vector<int>> dp(len_p, vector<int>(len_s, 0));
        dp[0][0] = 1;
        for(int i = 1; i < len_p; ++i) {
            dp[i][0] = (p[i] == '*' ? dp[i-1][0] : 0);
        }
        for(int i = 1; i < len_p; ++i) {
            for(int j = 1; j < len_s; ++j) {
                if(p[i] == '*') {
                    dp[i][j] = dp[i-1][j] ||
                               dp[i][j-1];
                }else{
                    dp[i][j] = dp[i-1][j-1] && (p[i] == '?' || p[i] == s[j]);
                }
            }
        }
        return dp[len_p-1][len_s-1];
     }
};
