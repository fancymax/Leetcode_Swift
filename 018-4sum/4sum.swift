// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        var resNums = [[Int]]()
        if nums.count < 4 {
            return resNums
        }
        
        let sortedNums = nums.sorted()
        
        for i in 0...sortedNums.count - 4 {
            if ((i > 0) && (sortedNums[i] == sortedNums[i - 1])) {
                continue
            }
            for j in i+1...sortedNums.count - 3 {
                if ((j > i + 1) && (sortedNums[j] == sortedNums[j - 1])) {
                    continue
                }
                var left = j + 1
                var right = sortedNums.count - 1
                let first = sortedNums[i]
                let second = sortedNums[j]
                while right > left {
                    let third = sortedNums[left]
                    let four = sortedNums[right]
                    let sum = first + second + third + four
                    if sum < target {
                        left += 1
                    }
                    else if sum > target {
                        right -= 1
                    }
                    else {
                        if ((left > j + 1) && (sortedNums[left] == sortedNums[left - 1])) {
                            left += 1
                        }
                        else {
                            resNums.append([first,second,third,four])
                            left += 1
                        }
                    }
                }
                
            }

        }
        
        return resNums
    }
}
