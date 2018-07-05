// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
         if (nums.size() == 0) {
            return  -1;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int pivot = start;
        bool isRotate = false;
        if (nums[end] < nums[start]) {
            isRotate = true;
            while (start < end) {
                int mid = start + (end - start)/2;
                if (nums[mid] >= nums[0]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            pivot = start;
        }

        start = 0;
        end = nums.size() - 1;
        if (isRotate) {
            if (target > nums[0]) {
                end = pivot - 1;
            }
            else if (target < nums[0]) {
                start = pivot;
            }
            else {
                return 0;
            }
        }

        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;    
    }
};
