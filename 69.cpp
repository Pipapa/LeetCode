#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }
        if(x == 2 || x == 3) {
            return 1;
        }
        int l = 0;
        int count = x >> 1;
        while(count > 0) {
            int step = count >> 1;
            int mid = l + step;
            if(x / mid > mid) {
                l = mid + 1;
                count -= step + 1;
            }else {
                count = step;
            }
        }
        return x / l < l ? l - 1 : l;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(1 == 1);
    assert(s.mySqrt(4) == 2);
    assert(s.mySqrt(8) == 2);
    assert(s.mySqrt(0) == 0);
    assert(s.mySqrt(1) == 1);
    assert(s.mySqrt(2) == 1);
}
