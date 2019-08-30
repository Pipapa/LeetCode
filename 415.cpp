class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string ans = "";
        int maxLen = std::max(len1, len2);
        while(num1.length() < maxLen) num1 = '0' + num1;
        while(num2.length() < maxLen) num2 = '0' + num2;
        int cnt = 0;
        for(int i = maxLen-1; i >= 0; --i) {
            int num = num1[i] - '0' + num2[i] - '0' + cnt;
            cnt = num / 10;
            num = num % 10;
            ans = (char)(num + '0') + ans;
        }
        if(cnt) ans = (char)(cnt + '0') + ans;
        return ans;
    }
};
