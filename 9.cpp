#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        char str[32] = {0};
        int len = 0;
        while(x){
            str[len++] = (x%10) + 'a';
            x/=10;
        }
        int l = 0 , r = len-1;
        while(l<=r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
