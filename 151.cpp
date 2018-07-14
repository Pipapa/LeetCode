#include <iostream>
#include <string>
using namespace std;

void reverseWords(string &s) {
    int len=s.size();
    int l=len-1,r=len-1;
    int slen=0;
    string ans="";
    while(s[slen]==' ') slen++;
    while(s[r]==' ') r--;
    if(len==0||(l==slen&&l==0)) return;
    while(r>=slen){
        l=r;
        while(s[l]!=' '&&l!=slen){l--;}
        if(s[l]==' '){
            for(int i=l+1;i<=r;i++) ans+=s[i];
            ans+=" ";
        }else if(l==slen){
            for(int i=slen;i<=r;i++) ans+=s[i];
        }
        r=l-1;
        while(s[r]==' ') r--;
    }
    s=ans;
}

int main(){
    string s;
    while(1){
        getline(cin,s);
        reverseWords(s);
        cout << s << endl;
    }
    return 0;
}