// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


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
    func addTwoNumbers(l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if(l1==nil)&&(l2==nil) {
            return nil
        }
        
        var ll1 = l1
        var ll2 = l2
        
        let head:ListNode? = ListNode(0)
        var point = head
        var previousEndPoint: ListNode?
        
        var carry = 0
        while (ll1 != nil) && (ll2 != nil) {
            point!.val = (ll1!.val + ll2!.val + carry)%10
            carry = (ll1!.val + ll2!.val + carry)/10
            point!.next = ListNode(0)
            previousEndPoint = point
            point = point!.next
            ll1 = ll1!.next
            ll2 = ll2!.next
        }
        
        while ll2 != nil {
            point!.val = (ll2!.val + carry)%10
            carry = (ll2!.val + carry)/10
            point!.next = ListNode(0)
            previousEndPoint = point
            point = point!.next
            ll2 = ll2!.next
        }
        
        while ll1 != nil {
            point!.val = (ll1!.val + carry)%10
            carry = (ll1!.val + carry)/10
            point!.next = ListNode(0)
            previousEndPoint = point
            point = point!.next
            ll1 = ll1!.next
        }
        
        if carry > 0 {
            point!.val = carry
        }
        else{
            previousEndPoint?.next = nil
        }
        
        return head
        
    }
}
