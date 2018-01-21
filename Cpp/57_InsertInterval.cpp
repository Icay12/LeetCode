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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size() == 0){
            res.push_back(newInterval);
            return res;
        }
        bool pushed = false;
        for(Interval i : intervals) {
            if(i.end < newInterval.start)
                res.push_back(i);
            else if(i.start > newInterval.end) {
                if(!pushed) {
                    res.push_back(newInterval);
                    pushed = true;
                }
                res.push_back(i);
                
            }
            else {
                newInterval.start = min(newInterval.start, i.start);
                newInterval.end = max(newInterval.end, i.end);
            }
        }
        if(!pushed) res.push_back(newInterval);
        return res;
    }
};