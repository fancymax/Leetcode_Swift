// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// Example 1:
//
//
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: 1
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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> changes;
        for (auto i : intervals) {
            changes[i.start] += 1;
            changes[i.end] -= 1;
        }
        int rooms = 0, maxrooms = 0;
        for (auto change : changes)
            maxrooms = max(maxrooms, rooms += change.second);
        return maxrooms;
    }
};
