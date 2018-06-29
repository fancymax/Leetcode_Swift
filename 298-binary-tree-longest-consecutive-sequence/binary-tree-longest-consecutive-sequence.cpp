// Given a binary tree, find the length of the longest consecutive sequence path.
//
// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
// Example 1:
//
//
// Input:
//
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
//
// Output: 3
//
// Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
//
// Example 2:
//
//
// Input:
//
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
//
// Output: 2 
//
// Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void exporeNode(TreeNode* node,TreeNode* lastNode,int lastLen,int& maxLen) {
        if (node == NULL) {
            return;
        }
        
        if (lastNode == NULL) {
            lastLen = 1;
        }
        else {
            if (node->val == lastNode->val + 1) {
                lastLen += 1;
                maxLen = max(maxLen, lastLen);
            }
            else {
                lastLen = 1;
            }
        }

        exporeNode(node->left, node, lastLen, maxLen);
        exporeNode(node->right, node, lastLen, maxLen);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxLen = 1;
        exporeNode(root, NULL, 0, maxLen);
        
        return maxLen;
    }
};
