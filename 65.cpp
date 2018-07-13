#include <string>
#include <iostream>
using namespace std;

bool isNum(char c){
    return c>='0' && c<='9';
}

bool isNumber(string s){
    int len=s.size()-1,pos=0;
    while(s[pos]==' ') pos++;
    while(s[len]==' ') len--;
    int status=7;
    for(;pos<=len&&status!=6;pos++){
        switch(status){
            case 7:
                if(pos==len && !isNum(s[pos])) return false;
                else if(s[pos]=='.') status=0;
                else if(isNum(s[pos])) status=1;
                else if(s[pos]=='+' || s[pos]=='-') status=5;
                else return false;
                break;
            case 5:
                if(isNum(s[pos])) status=1;
                else if(s[pos]=='.'){
                    status=0;
                    if(pos==len) return false;
                }
                else return false;
                break;
            case 0:
                if(isNum(s[pos])) status=2;
                else return false;
                break;
            case 1:
                if(isNum(s[pos])) status=1;
                else if(s[pos]=='.') status=2;
                else if(s[pos]=='E'||s[pos]=='e'){
                    status=3;
                    if(len==pos) return false;
                }
                else return false;
                break;
            case 2:
                if(isNum(s[pos])) status=2;
                else if(s[pos]=='E'||s[pos]=='e'){
                    status=3;
                    if(len==pos) return false;
                }
                else return false;
                break;
            case 3:
                if(isNum(s[pos])) status=4;
                else if(s[pos]=='+' || s[pos]=='-'){
                    if(len==pos) return false;
                    status=4;
                }
                else return false;
                break;
            case 4:
                if(isNum(s[pos])) status=4;
                else return false;
                break;
            default:
                return false;
        }
    }
    if(status==7) return false;
    return true;
}

int main(){
    string s;
    while(1){
        getline(cin,s);
        cout << isNumber(s) << endl;
    }
    
    return 0;
}