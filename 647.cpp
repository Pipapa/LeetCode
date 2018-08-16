#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countSubstrings(string s){
    string init_str = "#";
    int ans = 0;
    int p[100100]={0};
    for(int i=0;s[i]!='\0';i++) init_str = init_str + s[i] + "#";
    int str_len = init_str.size();
    int cent=0,bound=0;
    for(int i=0;i<str_len;i++){
        if(i<bound) p[i] = min(p[2*cent-i],bound-i);
        else p[i]=1;
        while(i-p[i]>=0 && init_str[i-p[i]] == init_str[i+p[i]]) p[i]++;
        if(bound < i+p[i]){bound=i+p[i],cent=i;}
        if(init_str[i] == '#') ans = ans + (p[i]-1)/2;
        else ans = ans + p[i]/2;
    }
    return ans;
}

int main(){
    cout << countSubstrings("abc") << endl;
    return 0;
}