#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    // num1 + num2 -> num2
    void add(std::vector<int> &num1,std::vector<int> &num2){
        int up = 0;
        int len1 = num1.size();
        int len2 = num2.size();
        int cnt = 0;
        while(cnt < len1 && cnt < len2){
            int tmp = num1[cnt] + num2[cnt] + up;
            up = 0;
            if(tmp >= 10){
                up = tmp/10;
                tmp = tmp%10;
            }
            num2[cnt] = tmp;
            cnt++;
        }
        while(cnt < len1){
            int tmp = num1[cnt] + up;
            up = 0;
            if(tmp >= 10){
                up = tmp/10;
                tmp = tmp%10;
            }
            num2.push_back(tmp);
            cnt++;
        }
        while(cnt < len2){
            int tmp = num2[cnt] + up;
            up = 0;
            if(tmp >= 10){
                up = tmp/10;
                tmp = tmp%10;
            }
            num2[cnt] = tmp;
            cnt++;
        }
        if(up) num2.push_back(up);
    }
    string multiply(string num1, string num2) {
        std::vector<int> ans;
        ans.clear();

        int len2 = num2.length();
        int len1 = num1.length();
        for(int i=len2-1;i>=0;--i){
            int up = 0;
            std::vector<int> tans;
            tans.clear();
            for(int j=i;j<len2-1;++j) tans.push_back(0);
            for(int j=len1-1;j>=0;--j){
                int tmp = (num1[j]-'0')*(num2[i]-'0')+up;
                up = 0;
                if(tmp >= 10){
                    up = tmp/10;
                    tmp = tmp%10;
                }
                tans.push_back(tmp);
            }
            if(up) tans.push_back(up);
            add(tans,ans);
        }
        string ret = "";
        int len = ans.size()-1;
        while(ans[len] == 0 && len>0) len--;
        while(len >= 0){
            ret = ret + char( ans[len] + '0' );
            len--;
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout << s.multiply("0","9133") << endl;
    return 0;
}
