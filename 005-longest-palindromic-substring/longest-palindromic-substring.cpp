// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {

public:
    string longestPalindrome(string s) {
        if ((s.length() == 0) || (s.length() == 1)) {
            return s;
        }
        
        int maxLength = 0;
        int maxStart = 0;
        int maxEnd = 0;
        
        for (int i = 0; (i < s.length()) && ((s.length() - i + 1) > maxLength); i++) {
            for (int j = s.length() - 1; j >= i; j--) {
                int start = i;
                int end = j;
                bool isPalindrome = true;
                while (start < end) {
                    if (s[start] != s[end]) {
                        isPalindrome = false;
                        break;
                    }
                    
                    start += 1;
                    end -= 1;
                }
                if (isPalindrome) {
                    int newLength = j - i + 1;
                    if (newLength > maxLength) {
                        maxLength = newLength;
                        maxStart = i;
                        maxEnd = j;
                    }
                    break;
                }
            }
        }
     
        return s.substr(maxStart,maxEnd - maxStart + 1);
    }
};
