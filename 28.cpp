class Solution {
public:
    vector<size_t> kmptable(const string& needle) {
        vector<size_t> ret(needle.size() + 1, 0);
        size_t k = 0;
        for(size_t i = 1; needle[i] != '\0'; ++i) {
            while(k > 0 && needle[k] != needle[i]) {
                k = ret[k];
            }
            needle[k] == needle[i] ? ++k : k;
            ret[i + 1] = k;
        }
        return ret;
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        auto table = kmptable(needle);
        size_t k = 0;
        size_t len = table.size() - 1;
        for(size_t i = 0; haystack[i] != '\0'; ++i) {
            while(k > 0 && haystack[i] != needle[k]) {
                k = table[k];
            }
            needle[k] == haystack[i] ? ++k : k;
            if(k == len) {
                return i + 1 - len;
            }
        }
        return -1;
    }
};
