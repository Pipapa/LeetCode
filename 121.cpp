#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int ans=0,len=prices.size(),min_p;
    if(len) min_p = prices[0];
    for(int i=1;i<len;i++){
        if(prices[i] < min_p) min_p = prices[i];
        else if(prices[i]-min_p > ans)
            ans = prices[i]-min_p;
    }
    return ans;
}

int main(){
    return 0;
}