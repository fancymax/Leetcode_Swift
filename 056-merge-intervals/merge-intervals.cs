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
 * public class Interval {
 *     public int start;
 *     public int end;
 *     public Interval() { start = 0; end = 0; }
 *     public Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public IList<Interval> Merge(IList<Interval> intervals) {
        if(intervals.Count() == 1)
        {
            return intervals;
        }
        
        var sortList = intervals.OrderBy(x => x.start).ToList();
        var res = new List<Interval>();
        
        for(int i=0; i<sortList.Count(); i++)
        {
            if(i == sortList.Count() - 1)
            {
                res.Add(sortList[i]);
                break;
            }
            
            if(CanMerge(sortList[i],sortList[i+1]))
            {
                Interval newInterval = MergeTwo(sortList[i],sortList[i+1]);
                sortList[i + 1] = newInterval;
            }
            else
            {
                res.Add(sortList[i]);
            }
        }
        return res;
    }
    
    private bool CanMerge(Interval a1, Interval a2)
    {
        if((a1.start <= a2.start)&&(a1.end >= a2.start))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    private Interval MergeTwo(Interval a1, Interval a2)
    {
        Interval res = new Interval();
        res.start = Math.Min(a1.start,a2.start);
        res.end = Math.Max(a1.end,a2.end);
        return res;
    }
}
