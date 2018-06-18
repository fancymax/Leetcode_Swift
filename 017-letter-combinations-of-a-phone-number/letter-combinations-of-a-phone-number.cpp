// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
private:
    void helper(vector<string> source,vector<string>& allResult, string& oneResult, int target, int k) {
        if (oneResult.length() == target) {
            string v1(oneResult);
            allResult.push_back(v1);
            return;
        }
        
        string current = source[k];
        for (int i = 0; i < current.size(); i++) {
            oneResult.push_back(current[i]);
            //进入下一层
            helper(source, allResult, oneResult, target, k + 1);
            
            oneResult.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        vector<string> source = {};
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == '2') {
                source.push_back("abc");
            }
            if (digits[i] == '3') {
                source.push_back("def");
            }
            if (digits[i] == '4') {
                source.push_back("ghi");
            }
            if (digits[i] == '5') {
                source.push_back("jkl");
            }
            if (digits[i] == '6') {
                source.push_back("mno");
            }
            if (digits[i] == '7') {
                source.push_back("pqrs");
            }
            if (digits[i] == '8') {
                source.push_back("tuv");
            }
            if (digits[i] == '9') {
                source.push_back("wxyz");
            }
        }
        
        int target = digits.length();
        string oneResult = "";
        vector<string> allResult = {};
        
        helper(source, allResult, oneResult, target, 0);
        
        return allResult;
    }
};
