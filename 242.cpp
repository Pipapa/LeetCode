#include <iostream>
#include <string>
bool IsAnagram(string s,string t){
    int arr[26]={0};
    int len_s = s.size();
    int len_t = t.size();
    if(len_s!=len_t) return false;
    for(int i=0;i<len_s;i++){
        arr[s[i]-97]++;
        arr[t[i]-97]--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]) return false;
    }
    return true;
}

int main(){
    return 0;
}