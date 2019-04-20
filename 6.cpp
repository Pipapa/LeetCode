#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ret = "";
        int len = s.length();
        for(int n=numRows;n>0;--n){
            int step = 2*(n-1);
            int lstep = 2*(numRows-n);
            int spos = numRows-n;
            while(spos < len){
                ret += s[spos];
                if(step) spos += step;
                else spos += lstep;
                if(spos < len) ret += s[spos];
                if(lstep) spos += lstep;
                else spos += step;
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout << s.convert("A",1) << endl;
    return 0;
}
