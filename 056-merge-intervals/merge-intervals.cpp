// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
//


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
        if (intervals.size() <= 1) {
            return intervals;
        }
        
//                sort(intervals.begin(),intervals.end(),mySort);
        sort(intervals.begin(),intervals.end(),[](Interval s1,Interval s2){
            return s1.start < s2.start;
        });
        
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i].end >= intervals[i+1].start) {
                intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
                intervals.erase(intervals.begin() + i + 1);
                
                i -= 1;
            }
        }
        
        return intervals;
    }
};
