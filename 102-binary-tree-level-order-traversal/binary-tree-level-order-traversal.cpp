// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        queue<TreeNode*> queueTree;
        queue<int> queueLevel;
        queueTree.push(root);
        queueLevel.push(0);
        
        while (!queueTree.empty()) {
            TreeNode* node = queueTree.front();
            queueTree.pop();
            
            int level = queueLevel.front();
            queueLevel.pop();
            
            if (node == NULL) {
                continue;
            }
            
            if (level + 1 > result.size()) {
                result.push_back({node->val});
            }
            else {
                result[level].emplace_back(node->val);
            }
            
            queueTree.push(node->left);
            queueTree.push(node->right);
            queueLevel.push(level + 1);
            queueLevel.push(level + 1);
        }
        
        return result;
    }
};
