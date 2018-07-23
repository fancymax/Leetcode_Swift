// Given two strings s and t, determine if they are both one edit distance apart.
//
// Note: 
//
// There are 3 possiblities to satisify one edit distance apart:
//
//
// 	Insert a character into s to get t
// 	Delete a character from s to get t
// 	Replace a character of s to get t
//
//
// Example 1:
//
//
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
//
//
// Example 2:
//
//
// Input: s = "cab", t = "ad"
// Output: false
// Explanation: We cannot get t from s by only one step.
//
// Example 3:
//
//
// Input: s = "1203", t = "1213"
// Output: true
// Explanation: We can replace '0' with '1' to get t.
//


class Solution {
public:
       bool isOneEditDistance(string s, string t) {
        int changeTimes = 0;
        //TODO: if length not same
        //TODO: if length same
        if (s.length() == t.length()) {
            if (s.length() == 0) {
                return  false;
            }
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != t[i]) {
                    changeTimes += 1;
                }
                
                if (changeTimes > 1) {
                    return false;
                }
            }
        }
        else if ((s.length() == t.length() + 1)||(s.length() + 1 == t.length())) {
            bool isSlonger = s.length() > t.length();
            long maxLength = max(t.length(), s.length());
            for (int i = 0; i < maxLength; i++) {
                if (((i >= s.length()) || (i >= t.length())) && (changeTimes == 0)) {
                    return true;
                }
                
                char s1;
                char t1;
                if (isSlonger) {
                    s1 = s[i];
                    t1 = t[i - changeTimes];
                }
                else {
                    s1 = s[i - changeTimes];
                    t1 = t[i];
                }
                
                if (s1 != t1) {
                    changeTimes += 1;
                }
                
                if (changeTimes > 1) {
                    return false;
                }
            }
        }
        else {
            return false;
        }
        
        
        if (changeTimes == 1) {
            return true;
        }
        else {
            return false;
        }

    }
    
};
