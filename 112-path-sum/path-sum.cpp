// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
//
//
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    void helper(TreeNode* node,int remain,bool& result) {
        if (node == NULL) {
            return;
        }
        
        int currentVal = remain - node->val;
        if ((!node->left)&&(!node->right)&&(currentVal == 0)) {
            result = true;
        }
        else {
            helper(node->left, currentVal, result);
            helper(node->right, currentVal, result);
        }
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;
        helper(root, sum, result);
        
        return result;
    }
};
