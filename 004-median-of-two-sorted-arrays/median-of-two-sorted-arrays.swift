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
    func findKth(numsA:[Int],startA:Int,numsB:[Int],startB:Int,kth:Int) -> Double {
    if startA >= numsA.count {
        return Double(numsB[startB + kth - 1])
    }
    
    if startB >= numsB.count {
        return Double(numsA[startA + kth - 1])
    }
    
    if kth == 1 {
        return Double(min(numsA[startA], numsB[startB]))
    }
    
    let Akey = (startA + kth / 2 - 1) >= numsA.count ? Int.max : numsA[startA + kth / 2 - 1]
    let Bkey = (startB + kth / 2 - 1) >= numsB.count ? Int.max : numsB[startB + kth / 2 - 1]
    
    if Akey < Bkey {
        return findKth(numsA: numsA, startA: startA + kth/2, numsB: numsB, startB: startB, kth: kth - kth/2)
    }
    else {
        return findKth(numsA: numsA, startA: startA, numsB: numsB, startB : startB + kth/2, kth: kth - kth/2)
    }
}
    
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
   let countA = nums1.count
    let countB = nums2.count
    if (countA + countB) % 2 == 0 {
        var kth = (countA + countB) / 2
        let n1 = findKth(numsA: nums1, startA: 0, numsB: nums2, startB: 0, kth: kth)
        kth += 1
        let n2 = findKth(numsA: nums1, startA: 0, numsB: nums2, startB: 0, kth: kth)
        return (n1 + n2) / 2
    }
    else {
        let kth = (countA + countB) / 2 + 1
        return findKth(numsA: nums1, startA: 0, numsB: nums2, startB: 0, kth: kth)
    }
    }
}
