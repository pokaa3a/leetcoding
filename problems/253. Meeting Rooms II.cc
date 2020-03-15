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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> time;     // time, start+1/end-1
        for(int i=0; i<intervals.size(); i++){
            time[intervals[i].start]++;
            time[intervals[i].end]--;
        }
        
        int count=0, max=0;
        for(auto i=time.begin(); i!=time.end(); i++){
            count += i->second;
            max = max>count?max:count;
        }
        return max;
    }
};