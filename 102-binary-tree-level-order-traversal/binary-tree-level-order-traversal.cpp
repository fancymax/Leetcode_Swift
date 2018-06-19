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
private:
    void explore(TreeNode* node,vector<vector<int>>& levelValues, int level) {
        if (!node) {
            return;
        }
        
        if (level >= levelValues.size()) {
            levelValues.push_back({});
        }
        levelValues[level].push_back(node->val);
        
        explore(node->left, levelValues, level + 1);
        explore(node->right, levelValues, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> levels = {};
        int level = 0;
        
        explore(root, levels, level);

        return levels;
    }
};
