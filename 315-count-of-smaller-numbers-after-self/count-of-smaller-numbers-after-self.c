// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;
    int* countArray = malloc(sizeof(int) * numsSize);
//    memset(countArray,0,sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        if (i == numsSize - 1) {
            count = 0;
        }
        else {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] < nums[i]) {
                    count += 1;
                }
            }
        }

        countArray[i] = count;
    }
    
    return countArray;
}
