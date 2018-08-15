/*
    LeetCode #338 Counting Bits
    https://leetcode.com/problems/counting-bits/
*/
#include <iostream>

const int maxn=10010;

int main(int argc,char *argv[]){
    int ans[maxn];
    ans[0] = 0;
    ans[1] = 1;
    int p = 1;
    int n;
    std::cin >> n;
    for(int i=2;i<=n;i++){
        if(i==2*p){
            p*=2;
        }
        ans[i] = ans[i-p] + 1;
    }
    return 0;
}