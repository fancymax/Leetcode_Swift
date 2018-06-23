// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
//
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
//
// Input: coins = [2], amount = 3
// Output: -1
//
//
// Note:
// You may assume that you have an infinite number of each kind of coin.
//


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int dp[amount + 1];
        memset(dp, -1, sizeof(dp));
        
        for (int i = 1; i <= amount; i++) {
            int minValue = -1;
            for (int j = 0; j < coins.size(); j++) {
                
                if (i - coins[j] < 0) {
                    continue;
                }
                else if (i - coins[j] == 0) {
                    minValue = 1;
                }
                else { // >0
                    if (dp[i-coins[j]] > 0) {
                        int val = dp[i-coins[j]] + 1;
                        if (minValue > 0) {
                            minValue = min(minValue, val);
                        }
                        else {
                            minValue =  val;
                        }
                    }
                }
                
                dp[i] = minValue;
            }
        }
        
        return dp[amount];
    }
};
