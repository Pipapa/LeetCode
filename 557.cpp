#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s){
    int s_=0,e=0,pos=0;
    string ans="";
    while(s[pos]!='\0'){
        s_=pos;
        while(s[pos]!=' '&&s[pos]!='\0') pos++;
        e=pos;
        for(int i=e-1;i>=s_;i--) ans+=s[i];
        if(s[pos]==' '){ans+=' ';pos++;};
    }
    return ans;
}

int main(){
    string s;
    while(1){
        getline(cin,s);
        cout << reverseWords(s) << endl;
    }
    return 0;
}