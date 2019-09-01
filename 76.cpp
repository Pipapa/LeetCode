class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> chTable;
        map<char, int> ansTable;
        
        int allCnt = t.length(), cnt = 0;
        int l = 0, rh = s.length() - 1;
        int ansL = 0;
        int ansR = rh;
        string ans = "";
        
        for(char ch = 'A'; ch <= 'Z'; ++ch) {
            chTable.insert(make_pair(ch, 0x4f4f4f4f));
            ansTable.insert(make_pair(ch, 0x3f3f3f3f));
        }
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            chTable.insert(make_pair(ch, 0x4f4f4f4f));
            ansTable.insert(make_pair(ch, 0x3f3f3f3f));
        }
        
        for(int i = 0; i < allCnt; ++i) {
            chTable[t[i]] = 0;
            if(ansTable[t[i]] == 0x3f3f3f3f) ansTable[t[i]] = 1;
            else ansTable[t[i]]++;
        }
        
        for(int r = 0; r <= rh; ++r) {
            if(chTable[s[r]] < ansTable[s[r]]) cnt++;
            chTable[s[r]]++;
            while(l < r && chTable[s[l]] > ansTable[s[l]]) {
                chTable[s[l]]--;
                l++;
            }
            // log
            if(cnt == allCnt) {
                if(r - l + 1 < ansR - ansL + 1) {
                    ansR = r;
                    ansL = l;
                }
            }
        }
        if(cnt != allCnt) return "";
        for(int i = ansL; i <= ansR; ++i) ans = ans + s[i];
        return ans;
    }
};
