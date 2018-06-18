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
 * public class Interval {
 *   public var start: Int
 *   public var end: Int
 *   public init(_ start: Int, _ end: Int) {
 *     self.start = start
 *     self.end = end
 *   }
 * }
 */
class Solution {
    struct RoomStatus {
        var time:Int
        var status:Int
        
        public init(_ time: Int, _ status: Int) {
            self.time = time
            self.status = status
        }
    }
    
    func minMeetingRooms(_ intervals: [Interval]) -> Int {
        var rooms:[RoomStatus] = intervals.map { (interval) -> RoomStatus in
            return RoomStatus(interval.start, 1)
        }
        let closed = intervals.map { (interval) -> RoomStatus in
            return RoomStatus(interval.end, -1)
        }
        
        rooms.append(contentsOf: closed)
        rooms.sort { (r1, r2) -> Bool in
            if r1.time == r2.time {
                return r1.status < r2.status
            }
            return r1.time < r2.time
        }
        
        var maxRoom = 0
        var usedRooms = 0
        for i in 0..<rooms.count {
            usedRooms += rooms[i].status
            maxRoom = max(maxRoom, usedRooms)
        }
   
        return maxRoom
    }

}
