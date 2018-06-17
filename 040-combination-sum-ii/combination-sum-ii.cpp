// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        vector<int> temp = {};
        sort(candidates.begin(),candidates.end());
        
        vector<int>v1(candidates);
        
        backtrack(res, temp, candidates, target, 0);
        
        
        return res;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int remain,int start) {
        if (remain < 0) {
            return;
        }
        else if (remain == 0) {
            
            bool isDuplicate = false;
            for (auto vs : result) {
                if (vs.size() != temp.size()) {
                    continue;
                }
                else {
                    bool isAllSame = true;
                    for (int i = 0; i < vs.size(); i++) {
                        if (vs[i] != temp[i]) {
                            isAllSame = false;
                            break;
                        }
                    }
                    if (isAllSame) {
                        isDuplicate = true;
                        break;
                    }
                }
            }
            if (!isDuplicate) {
                vector<int> v1(temp);
                result.push_back(v1);
            }
        }
        else {
            for (int i = start; i < nums.size(); i++) {
                temp.push_back(nums[i]);
                backtrack(result, temp, nums, remain - nums[i], i+1);
                temp.pop_back();
            }
        }
    }
};
