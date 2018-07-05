#include <iostream>
#include <string>
using namespace std;

/*
pr:
len - n >= n - 1
len >= 2*n -1
2*n <= len + 1
n <= (len + 1)/2
*/

string reorganizeString(string S){
    int arr[26]={0},n=-1,len=S.size(),t;
    char *ans = new char[len+1];
    for(int i=0;i<len;i++){
        arr[S[i]-'a']++;
        if(arr[S[i]-'a'] > n){ n=arr[S[i]-'a'];t=S[i]-'a';}
    }
    if(len < 2*n-1) return "";
    int f=(len+1)/2,f_=0,s_=1;
    while(arr[t]){f--;ans[f_]=t+'a';f_+=2;arr[t]--;}
    for(int i=0;i<26;i++){
        while(arr[i]){
            if(f){f--;ans[f_]=i+'a';f_+=2;}
            else{ans[s_]=i+'a';s_+=2;}
            arr[i]--;
        }
    }
    ans[len] = '\0';
    return string(ans);
}

int main(){
    cout << reorganizeString("vvvlo") << endl;
    return 0;
}