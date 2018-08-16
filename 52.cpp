#include <iostream>
using namespace std;

int ans = 0;
int vis[8] = {0};

bool check(int n){
    for(int i=0;i<n;i++){
        if(vis[n] == vis[i] || n-i == vis[n]-vis[i] || n-i == vis[i] - vis[n]) return false;
    }
    return true;
}

int totalNQueens(int n) {
    if(n==8) {ans++;return 0;}
    for(int i=0;i<8;i++){
        vis[n] = i;
        //check
        if(check(n)) totalNQueens(n+1); 
    }
    return 0;
}

int main(){
    totalNQueens(0);
    cout << ans << endl;
    return 0;
}