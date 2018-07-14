#include<iostream>
#include<string>
using namespace std;

bool isV(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'|| \
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

string reverseVowels(string s) {
    int l=0,r=s.size()-1;
    while(l<r){
        while(l<r&&!isV(s[r])) r--;
        while(l<r&&!isV(s[l])) l++;
        swap(s[l],s[r]);
        l++,r--;
    }
    return s;
}

int main(){
    string s;
    while(1){
        cin >> s;
        cout << reverseVowels(s) << endl;
    }
    return 0;
}