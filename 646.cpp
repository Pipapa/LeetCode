#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(),pairs.end(),cmp);       
    int ans=1;
    int min_bound=pairs[0][1];
    for(int i=1;i<pairs.size();i++){
        if(pairs[i][0] > min_bound){
            min_bound = pairs[i][1];
            ans++;
        }
    }
    return ans;
}

int main(){
    return 0
}