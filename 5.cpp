#include <iostream>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    string ans = "";
    string init_str = "#";
    for(int i=0;s[i]!='\0';i++) init_str = init_str + s[i] + '#';
    int bound=0,cent=0;
    int p[3010]={0};
    int max_len=0,max_pos=0;
    for(int i=0;init_str[i]!='\0';i++){
        if(i<bound) p[i]=min(p[2*cent-i],bound-i);
        else p[i]=1;
        while(i-p[i]>=0 && init_str[i-p[i]] == init_str[i+p[i]]) p[i]++;
        if(i+p[i] > bound){bound = i+p[i],cent=i;}
        if(p[i] > max_len){max_len=p[i],max_pos=i;}
    }
    for(int i=max_pos - p[max_pos] + 1;i<= max_pos+p[max_pos]-1;i++){
        if(init_str[i] != '#') ans = ans + init_str[i];
    }
    return ans;
}

int main(){
    cout << longestPalindrome("babad") << endl;
    return 0;
}