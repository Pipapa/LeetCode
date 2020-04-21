#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 1 << 31 && divisor == ~0) {
            return ~(1 << 31);
        }
        if(divisor == 1) {
            return dividend;
        }
        int negdd = dividend < 0 ? dividend : ~dividend + 1;
        int negdi = divisor < 0 ? divisor : ~divisor + 1;
        int sign = (divisor ^ dividend) >> 31;
        if(negdi < negdd) {
            return 0;
        }

        unsigned posdd = dividend > 0 ? dividend : 
                    dividend == (1 << 31) ? (1 << 31) : ~dividend + 1;
        unsigned posdi = divisor > 0 ? divisor : 
                    divisor == (1 << 31) ? (1 << 31) : ~divisor + 1;

        int a = 0;
        int m = posdi;
        int q = posdd;
        for(int i = 0; i < 32; ++i) {
            int s = (a >> 31) & 0x1;
            a = unsigned(a) << 1 | ((q >> 31) & 0x1);
            q = unsigned(q) << 1 & (~1);
            a = unsigned(a) + unsigned(~m) + 1;
            if(a < 0) {
                a = unsigned(a) + unsigned(m);
            }else {
                q = q | 0x1;
            }
        }
        if(sign) {
            return ~q + 1;
        }
        return q;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(1 == 1);
    assert(s.divide(10, 3) == 3);
    assert(s.divide(7, -3) == -2);
    assert(s.divide(1 << 31, -1) == ~(1 << 31));
    assert(s.divide(1 << 31, -2) == (1 << 31) / -2);
    assert(s.divide(1 << 31, 2) == (1 << 31) / 2);
    assert(s.divide(1 << 31, 3) == (1 << 31) / 3);
    return 0;
}
