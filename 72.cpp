class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.length() + 1;
        int len_2 = word2.length() + 1;
        int dp[1000][1000] = {0};
        for(int i = 0; i < len_2; ++i) {
            dp[0][i] = i;
        }
        for(int i = 0; i < len_1; ++i) {
            dp[i][0] = i;
        }
        for(int i = 1; i < len_1; ++i) {
            for(int j = 1; j < len_2; ++j) {
                int left = dp[i-1][j]+1;
                int up = dp[i][j-1]+1;
                int l_u = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) l_u++;
                dp[i][j] = min(min(left, up), l_u);
            }
        }
        return dp[len_1-1][len_2-1];
    }
};
