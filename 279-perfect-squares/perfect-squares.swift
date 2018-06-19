// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//


class Solution {

    //DP
    func numSquares(_ n: Int) -> Int {
        if n == 1 {
            return 1
        }
        
        var dp = Array<Int>(repeating: 0, count: n + 1)
        dp[1] = 1;
        
        for i in 2...n {
            for j in 1...n {
                let subKey = i - j*j
                if subKey < 0 {
                    break
                }
                if dp[i] == 0 {
                    dp[i] = dp[subKey]
                }
                else {
                    dp[i] = min(dp[i], dp[subKey])
                }
            }
            dp[i] += 1;
        }

        
        return dp[n]
    }
}
