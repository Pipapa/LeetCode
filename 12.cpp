#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string patern[9] = {
            "A",
            "AA",
            "AAA",
            "AB",
            "B",
            "BA",
            "BAA",
            "BAAA",
            "AC"
    };
    char p[4][3] = {
            'I','V','X',
            'X','L','C',
            'C','D','M',
            'M',' ',' '
    };
    string intToRoman(int num) {
        int ppos = 3;
        string ret = "";
        for(int base=1000;base>0;base/=10){
            int tmp = num / base;
            num %= base;
            if(tmp == 0){
                ppos--;
                continue;
            }
            string tp = patern[tmp - 1];
            for(int pos = 0;tp[pos]!='\0';++pos){
                ret += p[ppos][tp[pos]-'A'];
            }
            ppos--;
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout << s.intToRoman(1994) << endl;
    return 0;
}
