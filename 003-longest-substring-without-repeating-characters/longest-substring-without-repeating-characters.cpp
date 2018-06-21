// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ((s.length() == 0) || (s.length() == 1)) {
            return s.length() == 0 ? 0:1;
        }
        set<char> subString = {};
        int maxLength = 1;
        int onePassLength = 0;
        for (int i = 0; i < s.length(); i++) {
            subString = {s[i]};
            onePassLength = 1;
            for (int j = i + 1; j < s.length(); j++) {
                if (subString.find(s[j]) != subString.end()) {
                    break;
                }
                
                subString.insert(s[j]);
                onePassLength += 1;
                maxLength = max(maxLength, onePassLength);
            }
        }
        
        return maxLength;
    }
};
