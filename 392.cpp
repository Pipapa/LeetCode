#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int len_s=s.size(),count=0;
    for(int i=0;t[i]!='\0';i++){
        if(t[i] == s[count]) count++;
        if(count == len_s) break;
    }
    if(count == len_s) return true;
    return false;
}

int main(){
    return 0;
}