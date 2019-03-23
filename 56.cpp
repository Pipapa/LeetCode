/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<int> start;
        std::vector<int> end;
        std::vector<Interval> ans;
        for(int i=0;i<intervals.size();++i){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int startk = 0;
        if(start.size() == 1){
            ans.push_back(Interval(start[0],end[0]));
            return ans;
        }
        for(int i=1;i<start.size();++i){
            if(start[i] > end[i-1]){
                ans.push_back(Interval(start[startk],end[i-1]));
                startk = i;
            }
            if(i == start.size()-1){
                ans.push_back(Interval(start[startk],end[i]));
            }

        }
        return ans;
    }
};