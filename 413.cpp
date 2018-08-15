/*
    Leetcode #413 Arithmetic Slices
    https://leetcode.com/problems/arithmetic-slices

*/
#include <stdio.h>

const int maxn=10010;

int main(){
    int arr[maxn]={0};
    int n;
    scanf("%d",&n);
    int cnt=0;
    int ans=0;
    for(int i=2;i<n;i++){
        if(arr[i]-arr[i-1] == arr[i-1]-arr[i-2]){
            cnt++;
        }else{
            ans+=((1+cnt)*cnt/2);
            cnt=0;
        }
    }
    return 0;
}