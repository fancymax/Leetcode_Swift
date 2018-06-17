// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
// Note:
//
//
// 	Given target value is a floating point.
// 	You are guaranteed to have only one unique value in the BST that is closest to the target.
//
//
// Example:
//
//
// Input: root = [4,2,5,1,3], target = 3.714286
//
//     4
//    / \
//   2   5
//  / \
// 1   3
//
// Output: 4
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
    void helper(TreeNode* node, double target, double& min, double& val) {
        if (node->left) {
            double nodeValue = (double)node->left->val;
            if (abs(nodeValue - target) < min) {
                min = abs(nodeValue - target);
                val = nodeValue;
            }
            helper(node->left, target, min, val);
        }
        if (node->right) {
            double nodeValue = (double)node->right->val;
            if (abs(nodeValue - target) < min) {
                min = abs(nodeValue - target);
                val = nodeValue;
            }
            helper(node->right, target, min, val);
        }
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        
        double val = (double)root->val;
        double min = abs(val - target);
        
        helper(root, target, min, val);
        
        return val;
    }
};
