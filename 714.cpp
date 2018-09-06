#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
   /* int dp[50500][2]={0},len=prices.size(),ans=0;
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for(int i=1;i<len;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }
    return ans;*/
    //三状态 买，卖，持有 
    /*
    买 : 最大(上一次卖-prices[i] ,持有)
    卖 : 最大(上一次买+prices[i]-fee,持有)
    最后一股必定卖出
    */
    int len = prices.size();
    int hold_sock=-prices[0],sold_sock=0,t_hold_sock,t_sold_sock;
    for(int i=1;i<len;i++){
        t_hold_sock = max(sold_sock-prices[i],hold_sock);
        t_sold_sock = max(hold_sock+prices[i]-fee,sold_sock);
        hold_sock = t_hold_sock;
        sold_sock = t_sold_sock;
    }
    return sold_sock;
}

int main(){
    return 0;
}