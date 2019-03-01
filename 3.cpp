#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int len = 0;
        int start = 0;
        int table[128];
        for(int i=0;i<128;++i){table[i]=-1;}
        for(int i=0;s[i]!='\0';++i){
            if(table[s[i]] == -1 || start > table[s[i]]){
                len++;
                result = max(result,len);
            }else{
                result = max(result,i-start);
                start = table[s[i]]+1;
                len = i - start + 1;
            }
            table[s[i]] = i;
        }
        return result;
    }
};

int main(int argc,char *argv[]){
    return 0;
}
