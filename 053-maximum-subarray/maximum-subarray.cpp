// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = nums[0];
        
        int maxValue = nums[0];
        for (int i =1; i < nums.size(); i++) {
            dp[i] = dp[i - 1] < 0 ? nums[i] : dp[i - 1] + nums[i];
            maxValue = max(maxValue, dp[i]);
//            cout << maxValue << endl;
        }
        
        return maxValue;        
    }
};
