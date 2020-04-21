#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        unsigned p = n >= 0 ? unsigned(n) :
                     n == 1 << 31 ? unsigned(n) : unsigned(-n);
        x = n < 0 ? 1/x : x;
        while(p) {
            if(p & 1) {
                ret = x * ret;
            }
            x = x * x;
            p >>= 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(1 == 1);
    return 0;
}
