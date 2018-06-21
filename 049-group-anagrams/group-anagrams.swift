// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var dictMap = [String:[String]]();
        
        for str in strs {
            let characters = str.sorted { (s1, s2) -> Bool in
                return s1 < s2
            }
            let key = String(characters)
            
            if dictMap[key] != nil {
                dictMap[key]?.append(str)
            }
            else {
                dictMap[key] = [str]
            }
        }
        
        return dictMap.map({ (key,value) -> [String] in
            return value
        })
    }
}
