#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::map<string,int> string_map;
        vector<string> ans;
        for(string str : words) ++string_map[str];
        auto cmp = [](pair<string,int> &l,pair<string,int> &r){
            return l.second != r.second ? l.second < r.second : l.first > r.first;
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(cmp)> p_queue(cmp);
        for(auto each_pair : string_map) p_queue.push({each_pair.first,each_pair.second});
        for(int i=0;i<k;i++){
            ans.push_back(p_queue.top().first);
            p_queue.pop();
        }
        return ans;
    }
};

int main(){
    vector<string> in={"i", "love", "leetcode", "i", "love", "coding"};
    Solution s;
    for(auto str : s.topKFrequent(in,2)){
        cout << str << endl;
    }
    return 0;
}