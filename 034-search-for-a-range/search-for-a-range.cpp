// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
private:
    int findTargetIndex(vector<int>& nums,int target,int low,int high) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low)/2;
        if (nums[mid] == target) {
            return mid;
        }
        int left = findTargetIndex(nums, target, low, mid - 1);
        int right = findTargetIndex(nums, target, mid + 1, high);
        if (left != -1) {
            return left;
        }
        else if (right != -1) {
            return right;
        }
        else {
            return  -1;
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = findTargetIndex(nums, target, 0, nums.size() - 1);
        if (index < 0) {
            return {-1,-1};
        }
        else {
            int start = index;
            int end = index;
            while ((nums[start] == target) && (start >= 0)) {
                start -= 1;
            }
            while ((nums[end] == target)&&(end <= nums.size() - 1)) {
                end += 1;
            }
            start += 1;
            end -= 1;
            return {start,end};
        }
    }
};
