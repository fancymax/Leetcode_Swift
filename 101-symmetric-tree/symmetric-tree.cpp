// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//
// But the following [1,2,2,null,3,null,3]  is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
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
    bool helper(TreeNode* left,TreeNode* right) {
        if ((left == NULL)|| (right == NULL)) {
            return  left == right;
        }
        
        return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }
};
