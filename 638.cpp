#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
   int len_need = needs.size();
    int o0=0,o1=0,o2=0,o3=0,o4=0,o5=0;

    int dp[7][7][7][7][7][7] = {0};

    vector<int> new_prices;
    vector<int> np(6,0);
    vector<vector<int>> new_package;

    for(int i=0;i<price.size();i++){
        for(int x=1;x<=needs[i];x*=2){
            fill(np.begin(),np.end(),0);
            np[i] = x;
            new_package.push_back(np);
            new_prices.push_back(price[i]*x);
        }
    }

    for(int i=0;i<special.size();i++){
        int cnt = 100;
        vector<int> now_p = special[i];
        for(int c=0;c<needs.size();c++){
            if(needs[c] >= now_p[c] && 0!=now_p[c]){ cnt = min(cnt,needs[c]/now_p[c]);}
            else if(needs[c] < now_p[c]) {cnt = 100;break;}
        }
        if(cnt != 100){
            for(int x=1;x<=cnt;x*=2){
                fill(np.begin(),np.end(),0);
                for(int j=0;j<(now_p.size()-1);j++){
                    np[j] = now_p[j]*x;
                }
                new_package.push_back(np);
                new_prices.push_back(x*(now_p.back()));
            }
        }
    }


    for(int i=0;i<needs.size();i++){
        switch (i){
            case 0: o0=needs[0];break;
            case 1: o1=needs[1];break;
            case 2: o2=needs[2];break;
            case 3: o3=needs[3];break;
            case 4: o4=needs[4];break;
            case 5: o5=needs[5];break;
        }
    }
    for(int t0=o0;t0>=0;t0--){
        for(int t1=o1;t1>=0;t1--){
            for(int t2=o2;t2>=0;t2--){
                for(int t3=o3;t3>=0;t3--){
                    for(int t4=o4;t4>=0;t4--){
                        for(int t5=o5;t5>=0;t5--){
                            dp[t5][t4][t3][t2][t1][t0] = 200000;
                        }
                    }
                }
            }

        }

    }
    dp[0][0][0][0][0][0]=0;


    for(int i=0;i<new_package.size();i++){
        vector<int> tp = new_package[i];
        for(int t0=0;t0<=o0;t0++){
            for(int t1=0;t1<=o1;t1++){
                for(int t2=0;t2<=o2;t2++){
                    for(int t3=0;t3<=o3;t3++){
                        for(int t4=0;t4<=o4;t4++){
                            for(int t5=0;t5<=o5;t5++){
                                if(t0 >= tp[0] && t1 >= tp[1] \
                                        && t2 >= tp[2] && t3 >= tp[3] \
                                        && t4 >= tp[4] && t5 >= tp[5]){
                                    dp[t5][t4][t3][t2][t1][t0] = min(dp[t5][t4][t3][t2][t1][t0],
                                                                                        dp[t5-tp[5]][t4-tp[4]][t3-tp[3]][t2-tp[2]][t1-tp[1]][t0-tp[0]]+new_prices[i]);
                                }
                            }
                        }
                    }
                }

            }

        }
    }

    return dp[o5][o4][o3][o2][o1][o0];
}

int main(){
    vector<int> p = {2,3,4};
    vector<vector<int>> s = {{1,1,0,4},{2,2,1,9}};
    vector<int> n = {1,2,1};
    shoppingOffers(p,s,n);
    return 0;
}