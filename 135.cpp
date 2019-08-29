#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int ret = 0;
        vector<int> l2r(len, 1);
        vector<int> r2l(len, 1);
        for(int i = 1; i < len; ++i) {
            if(ratings[i] > ratings[i-1]) l2r[i] = l2r[i-1]+1;
            if(ratings[len-i-1] > ratings[len-i]) r2l[len-i-1] = r2l[len-i]+1;
        }

        for(int i = 0; i < len; ++i) {
            ret += std::max(l2r[i], r2l[i]);
        } 
        return ret;
    }
};
