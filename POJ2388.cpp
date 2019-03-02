#include <stdio.h>
#include <algorithm>
const int maxn = 10100;
int arr[maxn];

void qsort(int arr[],int l,int r){
    if(l >= r) return;
    // [l..r] 排序 , r 为基点
    int pos=l;
    for(int i=l;i<r;++i){
        if(arr[i] <= arr[r]){ std::swap(arr[i],arr[pos]);++pos;}
    }
    std::swap(arr[pos],arr[r]);
    qsort(arr,l,pos-1);
    qsort(arr,pos+1,r);
}

int main(int argc,char *argv[]){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    qsort(arr,0,n-1);
    printf("%d\n",arr[n/2]);
    return 0;
}
