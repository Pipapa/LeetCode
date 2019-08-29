#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    const char table[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> vis;
        unordered_set<string> bankSet;
        queue<string> visQueue;
        vis.clear(); bankSet.clear();
        for(auto it = bank.begin(); it != bank.end(); ++it) {
            bankSet.insert(*it);
        }
        if(bankSet.find(end) == bankSet.end()) return -1;
        if(end == start) return 0;
        vis.insert(start);
        visQueue.push(start);
        int left = 1;
        int ans = 0;
        bool find = false;
        while(!visQueue.empty() && !find) {
            ans++;
            int nextLeft = 0;
            for(int i = 0; i < left; ++i) {
                string& topStr = visQueue.front();
                visQueue.pop();
                for(int pos = 0; topStr[pos] != '\0'; ++pos) {
                    char pChar = topStr[pos];
                    for(int dlt = 0; dlt < 4; ++dlt) {
                        if(pChar == table[dlt]) continue;
                        topStr[pos] = table[dlt];
                        if(topStr == end) find = true;
                        if(bankSet.find(topStr) != bankSet.end() && vis.find(topStr) == vis.end()) {
                            vis.insert(topStr);
                            visQueue.push(topStr);
                            nextLeft++;
                        }
                    }
                    topStr[pos] = pChar;
                }
            }
            left = nextLeft;
        }
        if(!find) ans = -1;
        return ans;
    }
};

int main() {
	return 0;
}
