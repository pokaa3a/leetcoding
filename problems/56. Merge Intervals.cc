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
    static bool compare(Interval iv1, Interval iv2){
        return iv1.start<iv2.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int start=intervals[0].start, end=intervals[0].end;
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start>end){
                res.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            } else{
                end = end>intervals[i].end ? end : intervals[i].end;
            }
        }
        res.push_back(Interval(start,end));
        return res;
    }
};