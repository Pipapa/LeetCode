#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result=0;
        int sign = 1;
        int i=0;
        // remove the white
        while(i<str.size() && str[i]==' ') i++;
        if (str[i] == '-' || str[i] == '+')
            sign = str[i++] == '-' ? -1 : 1;
        for(;i < str.size();++i) {
            if(str[i] >= '0' && str[i] <= '9') {
                if (result > INT_MAX / 10)
                    return sign > 0?INT_MAX:INT_MIN;
                else if (result == INT_MAX / 10 && str[i] > '0' + INT_MAX % result)
                    return sign > 0?INT_MAX:INT_MIN;
                else
                    result = result * 10 + (str[i] - '0');
            }
            else
                break;
        }
        return result * sign;
    }
};

int main(){
    return 0;
}
