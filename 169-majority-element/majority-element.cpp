// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: 3
//
// Example 2:
//
//
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
//


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                majority = nums[i];
                cnt += 1;
            }
            else {
                if (majority == nums[i]) {
                    cnt += 1;
                }
                else {
                    cnt -= 1;
                }
                
                if (cnt > nums.size()/2) {
                    return majority;
                }
            }
        }

        return majority;
    }
};
