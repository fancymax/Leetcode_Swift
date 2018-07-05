// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result = {};
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> stackTree;
        
        stackTree.push(root);
        stackTree.push(root);
        
        while (!stackTree.empty()) {
            TreeNode* node = stackTree.top();
            stackTree.pop();
            
            TreeNode* lastNode = NULL;
            if (!stackTree.empty()) {
                lastNode = stackTree.top();
            }

            if (node == lastNode) {
                if (node->right) {
                    stackTree.push(node->right);
                    stackTree.push(node->right);
                }
                if (node->left) {
                    stackTree.push(node->left);
                    stackTree.push(node->left);
                }
            }
            else {
                if (node) {
                    result.push_back(node->val);
                }
            }
        }

        return result;
    }
};
