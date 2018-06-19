//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        if (s == "") {
            return -1;
        }
        
        unordered_map<char, int> allMap = {};
        for (int i = 0; i < s.size(); i++) {
            allMap[s[i]] += 1;
        }
        int minIndex = -1;
        for (int i = 0; i < s.size(); i++) {
            if (allMap[s[i]] == 1) {
                return i;
            }
        }

        return minIndex;
    }
};
