#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if(!n) return 1;
    int u=9,a=9,ans=10;
    while(n-- > 1 && a>0){
        u = u * a;
        ans += u;
        a--;
    }
    return ans;
}

int main(){
    return 0;
}