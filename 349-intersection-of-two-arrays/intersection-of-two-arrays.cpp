//
// Given two arrays, write a function to compute their intersection.
//
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//
// Note:
//
// Each element in the result must be unique.
// The result can be in any order.
//
//


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> table;
        for (int i = 0; i < nums1.size(); i++) {
            if (table.find(nums1[i]) == table.end()) {
                table[nums1[i]] = 0;
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (table.find(nums2[i]) != table.end()) {
                if (table[nums2[i]] == 0) {
                    table[nums2[i]] = 1;
                    res.emplace_back(nums2[i]);
                }
            }
        }
        
        return res;        
    }
};
