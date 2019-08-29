#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> lists(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        int ret = 0;
        int cnt = 0;
        if(lists.find(endWord) == lists.end()) return 0;
        queue<string> q;
        vis.clear();
        q.push(beginWord);
        vis.insert(beginWord);
        cnt++;
        while(!q.empty()) {
            ret++;
            int nextCnt = 0;
            // 拓展
            for(int i = 0; i < cnt; ++i) {
                string tmp = q.front();
                q.pop();

                for(int k = 0; tmp[k] != '\0'; ++k) {
                    char tCh = tmp[k];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(ch == tCh) continue;
                        tmp[k] = ch;
                        if(lists.find(tmp) != lists.end() &&
                           vis.find(tmp) == vis.end()) {
                            if(tmp == endWord) return ret+1;
                            vis.insert(tmp);
                            q.push(tmp);
                            nextCnt++;
                        }
                    }
                    tmp[k] = tCh;
                }
            }
            cnt = nextCnt;
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> arr = {"hot","dot","dog","lot","log","cog"};
    std::cout << s.ladderLength("hit", "cog", arr) << std::endl;
    return 0;
}
