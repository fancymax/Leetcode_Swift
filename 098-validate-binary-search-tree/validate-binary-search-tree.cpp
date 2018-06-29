// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than the node's key.
// 	The right subtree of a node contains only nodes with keys greater than the node's key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
// Example 1:
//
//
// Input:
//     2
//    / \
//   1   3
// Output: true
//
//
// Example 2:
//
//
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.
//
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
    bool isValidNode(TreeNode* node,TreeNode* maxNode,TreeNode* minNode) {
        if (node == NULL) {
            return true;
        }
        if (maxNode) {
            if (node->val >= maxNode->val) {
                return false;
            }
        }
        
        if (minNode) {
            if (node->val <= minNode->val) {
                return false;
            }
        }
        
        bool isLeftValid = false;
        if (maxNode) {
            if (node->val < maxNode->val) {
                isLeftValid = isValidNode(node->left, node, minNode);
            }
            else {
                isLeftValid = isValidNode(node->left, maxNode, minNode);
            }
        }
        else {
            isLeftValid = isValidNode(node->left, node, minNode);
        }
        
        bool isRightValid = false;
        if (minNode) {
            if (node->val > minNode->val) {
                isRightValid = isValidNode(node->right, maxNode, node);
            }
            else {
                isRightValid = isValidNode(node->right, maxNode, minNode);
            }
        }
        else {
            isRightValid = isValidNode(node->right, maxNode, node);
        }
        
        return isLeftValid&&isRightValid;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, NULL, NULL);
    }
};
