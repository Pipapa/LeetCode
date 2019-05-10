#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 100100;

int main(){
    int n,m;
    int arr[maxn];
    while(~scanf("%d%d",&n,&m)){
        int l = -1 , r = 0;
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            l = max(l,arr[i]);
        }
        r = l * n;
        int mid;
        while(l < r){
            mid = (l+r)/2;
            int cnt = 1;
            int sum = 0;
            for(int i=0;i<n;++i){
                if(sum + arr[i] <= mid){
                    sum += arr[i];
                }else{
                    sum = arr[i];
                    cnt++;
                }
            }
            if(cnt > m) l = mid+1;
            else r = mid;
        }
        printf("%d\n",l);

    }
    return 0;
}