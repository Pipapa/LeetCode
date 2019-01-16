#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static bool cmp(const vector<int> &l ,const vector<int> &r){
        return l[0]*l[0]+l[1]*l[1] < r[0]*r[0]+r[1]*r[1];
    }
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
        vector<vector<int> > ans;
        sort(points.begin(),points.end(),cmp);
        for (int i = 0; i < K; ++i) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}