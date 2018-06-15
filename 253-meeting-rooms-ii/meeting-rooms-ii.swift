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
       func minMeetingRooms(_ intervals: [Interval]) -> Int {
          var roomChnage = [Int:Int]()
        for interval in intervals {
            if let _ = roomChnage[interval.start] {
                roomChnage[interval.start]! += 1
            }
            else {
                roomChnage[interval.start] = 1
            }
            
            if let _ = roomChnage[interval.end] {
                roomChnage[interval.end]! -= 1
            }
            else {
                roomChnage[interval.end] = -1
            }
        }
        
        let sortedRoomChange = roomChnage.sorted { (v1, v2) -> Bool in
            return v1.key < v2.key
        }
        
        var maxRoom = 0
        var room = 0
        for changeRoomItem in sortedRoomChange {
            room += changeRoomItem.value
            maxRoom = max(maxRoom, room)
        }
      
        return maxRoom
    }
    
   
}
