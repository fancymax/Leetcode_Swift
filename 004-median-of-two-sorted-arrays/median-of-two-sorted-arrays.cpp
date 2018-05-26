// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
//
// Example 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
   
        vector<int> longArray = nums1;
        vector<int> shortArray = nums2;


        if (shortArray.size() > longArray.size()) {
            longArray = nums2;
            shortArray = nums1;
        }
        
        unsigned long startIndex = 0;
        auto finalIndex = longArray.size();
        for (int i = 0; i < shortArray.size(); i++) {
            finalIndex = longArray.size();
            auto val1 = shortArray[i];
            
            while (true) {
                
                if (startIndex >= finalIndex) {
                    if (val1 < longArray[finalIndex]) {
                        longArray.insert(longArray.begin() + finalIndex,val1);
                    }
                    else {
                        if (finalIndex >= longArray.size() - 1) {
                            longArray.push_back(val1);
                        }
                        else {
                            longArray.insert(longArray.begin() + finalIndex + 1,val1);
                        }
                    }
                    break;
                }
                
                auto compareIndex = (startIndex + finalIndex) / 2;
                auto val2 = longArray[compareIndex];
                if (val1 < val2) {
                    if (compareIndex == 0) {
                        finalIndex = 0;
                    }
                    else {
                        finalIndex = compareIndex - 1;
                    }
                }
                else if (val1 > val2) {
                    startIndex = compareIndex + 1;
                    
                }
                else {
                    longArray.insert(longArray.begin() + compareIndex,val1);
                    break;
                }

            }
        }
        
        auto middle = longArray.size() / 2;
        if (longArray.size() % 2 == 0) {
            return ((double)(longArray[middle - 1] + longArray[middle]))/2.0;
        }
        else {
            return (double)longArray[middle];
        }
    }
};
