class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = s.length() - 1;
        if(r < 0) return 0;
        int lh = 0, rh = 0;
        char ch1 = s[0], ch2 = s[0];
        int ch1N = 1, ch2N = 1;
        int chCnt = 1;
        int ans = 0;
        rh++;
        while(rh <= r) {
            if(s[rh] == ch1) ch1N++;
            if(s[rh] == ch2) ch2N++;
            
            if(s[rh] != ch1 && s[rh] != ch2) {
                if(chCnt < 2) {
                    if(ch2N != 0) {
                        ch1N = 1;
                        ch1 = s[rh];
                    } else {
                        ch2N = 1;
                        ch2 = s[rh];
                    }
                    chCnt++;
                }else {
                    ans = max(ans, rh - lh);
                    while(lh < rh && ch1N > 0 && ch2N > 0) {
                        if(s[lh] == ch1) ch1N--;
                        else if(s[lh] == ch2) ch2N--;
                        lh++;
                    }
                    if(ch1N == 0) {
                        ch1 = s[rh];
                        ch1N = 1;
                    }
                    if(ch2N == 0) {
                        ch2 = s[rh];
                        ch2N = 1;
                    }
                }
            }
            rh++;
        }
        ans = max(ans, rh - lh);
        return ans;
    }
};
