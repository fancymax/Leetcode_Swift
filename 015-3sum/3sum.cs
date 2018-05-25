// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


public class Solution {
    public List<List<int>> ThreeSum(int[] nums) {
        List<List<int>> res = new List<List<int>>();
        if(nums.Length < 3)
        {
            return res;
        }
        Array.Sort(nums);
        for(int i=0;i<nums.Length-2;i++)
        {
            if((i > 0)&&(nums[i] == nums[i-1]))
            {
                continue;
            }
            for(int j=i+1;j<nums.Length-1;j++)
            {
                if((j > i+1)&&(nums[j] == nums[j-1]))
                {
                    continue;
                }
                for(int z=j+1;z<nums.Length;z++)
                {
                    if(nums[i]+nums[j]+nums[nums.Length-1] < 0)
                    {
                        break;
                    }
                    
                    if(j >= z)
                    {
                        break;
                    }
                    
                    if(nums[i]+nums[j]+nums[z] > 0)
                    {
                        break;
                    }

                    if(nums[i]+nums[j]+nums[z] == 0)
                    {
                        res.Add(Add(nums[i],nums[j],nums[z]));
                        break;
                    }
                }
            }
        }
        return res;
    }
    
    public List<int> Add(int a,int b,int c){
        List<int> threeSet = new List<int>();
        threeSet.Add(a);
        threeSet.Add(b);
        threeSet.Add(c);
        return threeSet;
    }
}
