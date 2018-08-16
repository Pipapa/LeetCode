#include <iostream>
#include <string>
#include <vector>
using namespace std;

int vis[8] = {0};
vector<vector<string>> ans;

bool check(int n){
    for(int i=0;i<n;i++){
        if(vis[n] == vis[i] || n-i == vis[n]-vis[i] || n-i == vis[i] - vis[n]) return false;
    }
    return true;
}

int totalNQueens(int n) {
    if(n==8) {
        vector<string> ans_str;
        for(int i=0;i<8;i++){
            string line(8,'.');
            line[vis[i]] = 'Q';
            ans_str.push_back(line);
        }
        ans.push_back(ans_str);
    }
    for(int i=0;i<8;i++){
        vis[n] = i;
        //check
        if(check(n)) totalNQueens(n+1); 
    }
    return 0;
}

int main(){
    totalNQueens(0);
    return 0;
}