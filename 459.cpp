#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<size_t> table(s.size() + 1, 0);
        size_t k = 0;

        for(size_t i = 1; s[i] != '\0'; ++i) {
            while(k > 0 && s[i] != s[k]) {
                k = table[k];
            }
            s[i] == s[k] ? ++k : k;
            table[i + 1] = k;
        }

        size_t len = s.size();
        size_t cycle = len - table[len];

        if(len % cycle || len == cycle) {
            return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.repeatedSubstringPattern("abaababaab") == 1);
    assert(s.repeatedSubstringPattern("abab") == 1);
    assert(s.repeatedSubstringPattern("aba") == 0);
    assert(s.repeatedSubstringPattern("abcabcabcabc") == 1);
    assert(s.repeatedSubstringPattern("ababcababc") == 1);
    assert(s.repeatedSubstringPattern("aaa") == 1);
    assert(s.repeatedSubstringPattern("abac") == 0);
    assert(s.repeatedSubstringPattern("aabaaba") == 0);
    assert(s.repeatedSubstringPattern("aa") == 1);
    return 0;
}
