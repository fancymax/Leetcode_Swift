// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        int maxCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            int j = i - 1;
            
            int singleMax = 1;
            while (j >= 0) {
                if (nums[i] > nums[j]) {
                    singleMax = max(singleMax, dp[j] + 1);
                }
                
                j -= 1;
            }
            dp[i] = singleMax;

//             cout << "index = " << i << "   " << dp[i] << "\n";
            maxCount = max(maxCount, dp[i]);
        }
        
        return maxCount;   
    }
};
