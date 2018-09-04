#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans=0,len=prices.size();
    for(int i=1;i<len;i++){
        if(prices[i] > prices[i-1]) ans += (prices[i]-prices[i-1]);
    }
    return ans;
}

int main(){
    return 0;
}