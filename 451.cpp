#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[128] = {0};

bool cmp(int i,int j){
    return arr[i] > arr[j];
}

string frequencySort(string s){
    int ch_heap[128]={0},len=s.size();
    string ans="";
    for(int i=0;i<128;++i){ch_heap[i]=i;}
    for(int i=0;i<len;++i){arr[s[i]]++;}
    sort(ch_heap,ch_heap+128,cmp);
    for(int i=0;i<128;++i){
        if(arr[ch_heap[i]] == 0) break;
        while(arr[ch_heap[i]]--){
            ans += ch_heap[i];
        }
    }
    return ans;
}

int main(){
    cout << frequencySort("cccaaa") << endl;
    return 0;
}