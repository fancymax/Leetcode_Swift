// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result = {};
        stack<TreeNode*> stackTree;
        stackTree.push(root);
        
        while (!stackTree.empty()) {
            TreeNode* node = stackTree.top();
            stackTree.pop();
            
            if (node == NULL) {
                continue;
            }
            result.push_back(node->val);
            
            stackTree.push(node->right);
            stackTree.push(node->left);
        }
        
        return result;
    }
};
