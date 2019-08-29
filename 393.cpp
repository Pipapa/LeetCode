#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    inline int GetUTFType(int n) {
        const unsigned mask = 0x80;
        int cnt = 0;
        for(cnt = 0; cnt <= 5; ++cnt) {
            if(!((mask >> cnt)&(unsigned)n)) return cnt;
        }
        return cnt;
    }

    bool validUtf8(vector<int>& data) {
        auto it = data.begin();
        int left = 0;
        while (it != data.end()) {
            int status = GetUTFType(*it);
            switch (status) {
                case 0:
                    it++;
                    break;
                case 1:
                    return false;
                case 2:
                case 3:
                case 4:
                    left = status - 1;
                    it++;
                    for(int i = 0; i < left; ++i) {
                        if(it == data.end()) return false;
                        if(1 != GetUTFType(*it)) return false;
                        it++;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.GetUTFType(0b10111111) << endl;
    cout << s.GetUTFType(0b11011111) << endl;
    cout << s.GetUTFType(0b11101111) << endl;
    cout << s.GetUTFType(0b11110000) << endl;
    cout << s.GetUTFType(0b01111111) << endl;
    cout << s.GetUTFType(0b11111111) << endl;

    return 0;
}
