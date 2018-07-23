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
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates,target,0);
    }
    
    vector<vector<int>> helper(vector<int>& candidates, int target, int start) {
        vector<vector<int>> result = {};
        
        for(int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] > 0) {
                auto tmpResult = helper(candidates, target - candidates[i],i);
                
                if (tmpResult.size() == 0) {
                    continue;
                }
                //TODO: combine with candidates[i]
                for (int j = 0; j < tmpResult.size(); j++) {
                    tmpResult[j].push_back(candidates[i]);
                    
                    //TODO: Add to result
                    result.push_back(tmpResult[j]);
                }
            }
            else if (target - candidates[i] == 0) {
                result.push_back({candidates[i]});
            }
            
        }
        
        return result;
    }
};
