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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* helper(ListNode* sub1,ListNode* sub2,int addon,bool isRoot) {
        int left = 0;
        ListNode* newSub1 = NULL;
        if (sub1 != NULL) {
            left = sub1->val;
            newSub1 = sub1->next;
        }
        int right = 0;
        ListNode* newSub2 = NULL;
        if (sub2 != NULL) {
            right = sub2->val;
            newSub2 = sub2->next;
        }
        int total = left + right + addon;
        if ((total != 0) || newSub1 || newSub2) {
            int newAddon = total/10;
            ListNode* node = new ListNode(total%10);
            node->next = helper(newSub1, newSub2, newAddon,false);
            return node;
        }
        else {
            if (isRoot) {
                return new ListNode(0);
            }
            else {
                return NULL;
            }
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0,true);
    }
};
