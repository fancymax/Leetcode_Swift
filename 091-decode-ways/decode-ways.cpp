// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//


class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        int dp[s.length() + 1];
        dp[0] = 0;
        if ((s[0] >= '1') && (s[0] <= '9')) {
            dp[1] = 1;
        }
        else {
            dp[1] = 0;
        }
        if (s.length() == 1) {
            return dp[1];
        }
        
        for (int i = 2; i <= s.length(); i++) {
            int x1 = s[i - 2] - '0';
            int x2 = s[i - 1] - '0';
            int x3 = x1 * 10 + x2;
            
            int k1 = 0;
            if ((x2 >= 1) && (x2 <= 9)) {
                k1 = 1;
            }
            int k2 = 0;
            if ((x3 >= 10) && (x3 <= 26) ) {
                k2 = 1;
            }
            
            if (i == 2) {
                dp[i] = k1 * dp[i - 1] + k2 * 1;
            }
            else {
                dp[i] = k1 * dp[i - 1] + k2 * dp[i - 2];
            }
        }
        
        return dp[s.length()];
    }
};
