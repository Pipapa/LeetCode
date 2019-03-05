#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int max = (int)0x7fffffff / 10;
        int min = (int)0x80000000 / 10;
        while(x){
            int t = x%10;
            x/=10;
            if(result > max || (result == max && t > 7)) return 0;
            if(result < min || (result == min && t < -8)) return 0;
            result = result*10+t;
        }
        return result;
    }
};

int main(){
    Solution s;
    s.reverse(123);
    return 0;
}
