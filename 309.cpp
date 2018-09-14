#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1) return 0;
    int s0,s1,s2,old_s0,old_s1,old_s2;
    old_s0 = 0 , old_s1 = -prices[0] , old_s2 = 0;
    for(int p : prices){
        s0 = max(old_s0,old_s2);
        s1 = max(old_s1,old_s0 - p);
        s2 = old_s1 + p;
        old_s0 = s0,old_s1 = s1,old_s2 = s2;
    }
    return max(s0,s2);
}

int main(){
    return 0;
}