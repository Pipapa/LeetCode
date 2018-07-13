#include <iostream>
#include <set>
#include <string>
using namespace std;

string mapped[26]={
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--.."};

int main(){
    set<string> uns;
    string ans="",pob="xxx";
    for(int i=0;i<pob.size();i++){
        ans = ans + mapped[pob[i]-'a'];
    }
    uns.insert(ans);
    return 0;
}