/*
    LeetCode #343 Interger Break
    https://leetcode.com/problems/integer-break

*/
#include <stdio.h>

const int maxn=10010;

inline int max(int a,int b){
    return a>b?a:b;
}

int main(){
    int n;
    int a[maxn]={0};
    a[1] = a[2] = 1;
    scanf("%d",&n);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            a[i] = max(a[i],max(max(j*(i-j),a[j]*a[i-j]),max(a[j]*(i-j),j*a[i-j])));
        }
    }
    printf("%d\n",a[n]);
    return 0;
}