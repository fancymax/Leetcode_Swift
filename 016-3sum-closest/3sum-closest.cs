// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        
        int left = 1;
        int right = nums.Length - 1;
        int min = nums[0] + nums[left] + nums[right];

        for(int i=0;i<nums.Length-2;i++)
        {
            left = i + 1;
            right = nums.Length - 1;
   
            while(left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if (Math.Abs(temp - target) < Math.Abs(min - target))
                {
                    min = temp;
                }
                
                if(temp < target)
                {
                    left += 1;
                }
                else if (temp > target)
                {
                    right -= 1;
                }
                else
                {
                    return temp;
                }
            }
        }
        return min;
    }
    
    
}
