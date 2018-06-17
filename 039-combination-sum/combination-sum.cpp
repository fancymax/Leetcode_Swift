// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
private:
    void backtrack(vector<vector<int>>& result,vector<int>& temp,vector<int>& nums, int remain,int start) {
        if (remain < 0) {
        }
        else if (remain == 0 ) {
            vector<int > v1(temp);
            result.push_back(v1);
        }
        else {
            for (int i = start; i < nums.size(); i++) {
                temp.push_back(nums[i]);
                backtrack(result, temp, nums, remain - nums[i], i);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        vector<int> temp = {};
        backtrack(res, temp, candidates, target, 0);
        

        return res;
    }
};
