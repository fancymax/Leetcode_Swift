// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution.
//
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//
//
//
// UPDATE (2016/2/13):
// The return format had been changed to zero-based indices. Please read the above updated description carefully.


class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        for i in 0...nums.count - 1 {
            for j in i + 1...nums.count - 1 {
                if nums[i] + nums[j] == target {
                    return [i,j]
                }
            }
        }
        
        return []
    }
}
