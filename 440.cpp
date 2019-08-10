#include <iostream>
#include <stack>

class Solution {
public:
    int GetNodeNums(int n, int max) {
        int  ans = 1;
        long left  = n * 10 + 0;
        long right = n * 10 + 9;
        while(max >= left) {
            if(max <= right){
                ans += (max - left + 1);
            }else{
                ans += (right - left + 1);
            }
            left  = left  * 10 + 0;
            right = right * 10 + 9;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        int l = 1;
        int r = 9;
        while(k) {
            for(int i = l; i <= r; ++i) {
                int f = GetNodeNums(i, n);
                if(k > f) {
                    k -= f;
                }else {
                    k--;
                    if(k == 0) return i;
                    l = i * 10 + 0;
                    r = i * 10 + 9;
                    break;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    std::cout << s.GetNodeNums(1, 107) << std::endl;
    std::cout << s.GetNodeNums(10, 107) << std::endl;
    std::cout << s.GetNodeNums(11, 107) << std::endl;
    std::cout << s.findKthNumber(13, 2) << std::endl;
    std::cout << s.findKthNumber(100, 10) << std::endl;
    std::cout << s.findKthNumber(2, 2) << std::endl;
    return 0;
}
