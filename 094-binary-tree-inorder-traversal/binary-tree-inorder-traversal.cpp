// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = {};
        stack<TreeNode*> stackTree;
        
        TreeNode* node = root;
     
        while ((!stackTree.empty())||(node != NULL)) {
            if (node != NULL) {
                stackTree.push(node);
                node = node->left;
            }
            else {
                node = stackTree.top();
                stackTree.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }

        return result;
    }
};
