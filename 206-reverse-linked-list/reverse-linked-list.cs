// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
//


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if((head == null)||(head.next == null))
        {
            return head;
        }
        
        int nodeNum = 1;
        Dictionary<int,int> nodeDic = new Dictionary<int,int>();
        nodeDic.Add(nodeNum,head.val);
        var nextNode = head.next;
        //获取总长度，并构造index和value的字典
        while(nextNode != null)
        {
            nodeNum++;
            nodeDic.Add(nodeNum,nextNode.val);
            nextNode = nextNode.next;
        }
        
        //reverse
        int nodeIndex = 1;
        head.val = nodeDic[nodeNum + 1 - nodeIndex];
        nextNode = head.next;
        while(nextNode != null)
        {
            nodeIndex++;
            nextNode.val = nodeDic[nodeNum + 1 - nodeIndex];
            nextNode = nextNode.next;
        }
        return head;
    }
}
