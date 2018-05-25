// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Example
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
//
//


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func getValFromNode(_ node:ListNode?) -> Int {
        if node == nil {
            return 0
        }
        else {
            return node!.val
        }
     }
    
    func getNextNode(_ node:ListNode?) ->ListNode? {
        if node != nil {
            return node!.next
        }
        else {
            return nil
        }
    }
    
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if(l1==nil)&&(l2==nil) {
            return nil
        }
    
        var ll1 = l1
        var ll2 = l2
    
        let head = ListNode(0)
        var point = head
        var carry = 0
    
        while (ll1 != nil) || (ll2 != nil) || carry != 0 {
            let total = getValFromNode(ll1) + getValFromNode(ll2) + carry
            point.val = total % 10
            carry = total / 10
        
            ll1 = getNextNode(ll1)
            ll2 = getNextNode(ll2)
            if ll1 != nil || ll2 != nil || carry != 0 {
                point.next = ListNode(0)
                point = point.next!
            }
        }
    
        return head
    }
}
