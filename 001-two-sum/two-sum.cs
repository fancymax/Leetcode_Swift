// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//
//  
//


public class Solution {
    
    public int[] getResult(int index1,int index2)
    {
        if(index1 < index2)
        {
            return new int[2]{index1 + 1,index2 + 1};
        }
        else
        {
            return new int[2]{index2 + 1,index1 + 1};
        }
    }
    
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> origin = new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++)
        {
            if(origin.ContainsKey(nums[i]))
            {
                //handle the duplicate
                if (nums[i]*2 == target)
                {
                    return getResult(origin[nums[i]],i);
                }
            }
            else
            {
                origin.Add(nums[i],i);
            }
        }
        
        for(int i=0;i<nums.Length;i++)
        {
            int nextVal = target - nums[i];
            if (nextVal == nums[i])
            {
                continue;
            }
            if(origin.ContainsKey(nextVal))
            {
                return getResult(i,origin[nextVal]);
            }
        }
        
      
        return new int[2]{0,0};
    }
}
