#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<char,int> table = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
    };
    int romanToInt(string s) {
        int ret = 0 , len = s.length() - 1;
        int now = 0;
        for(;len>=0;--len){
            if(table[s[len]] < now){
                ret -= table[s[len]];
            }else{
                ret += table[s[len]];
            }
            now = table[s[len]];
        }
        return ret;
    }
};

int main(){
    return 0;
}
