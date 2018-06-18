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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* helper(ListNode *parent, ListNode* node) {
        ListNode* newParent;
        if (node != NULL) {
            newParent = node->next;
            node->next = parent;
            
            if (newParent != NULL) {
                newParent = helper(node, newParent);
            }
        }
        else {
            newParent = NULL;
        }

        if (newParent != NULL) {
            return newParent;
        }
        else {
            return node;
        }
        
    }
public:
    ListNode* reverseList(ListNode* head) {
        return helper(NULL, head);
    }
};
