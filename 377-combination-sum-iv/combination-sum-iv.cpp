//  Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
    int* dp;
    bool isInit = false;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (!isInit) {
            dp = new int[target + 1];
            for (int i = 0; i<target + 1; i++) {
                dp[i] = -1;
            }
            isInit = true;
        }
        
        if (dp[target] >= 0) {
            return dp[target];
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] > 0) {
                res += combinationSum4(nums, target - nums[i]);
            }
            else if (target - nums[i] == 0) {
                res += 1;
            }
        }
        
        dp[target] = res;
        
        return res;
    }
};
