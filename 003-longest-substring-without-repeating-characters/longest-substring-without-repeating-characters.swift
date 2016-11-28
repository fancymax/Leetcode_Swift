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
    func lengthOfLongestSubstring(_ s: String) -> Int {
        
        var characterDict = [Character:Int]()
        var maxLength = 0
        var lastRepeatPos = -1
        var i = 0
        
        for c in s.characters {
            if (characterDict[c] != nil) && (characterDict[c]! > lastRepeatPos) {
                lastRepeatPos = characterDict[c]!
            }
            
            maxLength = max(i - lastRepeatPos, maxLength)
            characterDict[c] = i
            i += 1
        }
        
        return maxLength
    }
}
