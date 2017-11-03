//
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
//
// For example,
// Given sorted array nums = [1,1,1,2,2,3],
//
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
//


public class Solution {
    HashSet<int> pre = new HashSet<int>();
    HashSet<int> cur = new HashSet<int>();
    public int RemoveDuplicates(int[] nums) {
 
        int removeCount = 0;

        for(int i =0; i< (nums.Length - removeCount); i++)
        {
            if(!pre.Contains(nums[i]))
            {
                pre.Add(nums[i]);
            }
            else if(!cur.Contains(nums[i]))
            {
                cur.Add(nums[i]);
            }
            else
            {
                if((i+1)==nums.Length)
                {
                    removeCount++;
                    break;
                }
                
                int newLen = nums.Length - removeCount - i - 1;
                //数据前移
                for(int j =0; j < newLen; j++)
                {
                    nums[i+j]=nums[i+j+1];
                }
                
                removeCount++;

                i--;
            }
        }

        return (nums.Length - removeCount);
    }
}
