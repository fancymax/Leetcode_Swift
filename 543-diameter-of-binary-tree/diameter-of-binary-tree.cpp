//
// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//
//
// Example:
// Given a binary tree 
//
//           1
//          / \
//         2   3
//        / \     
//       4   5    
//
//
//
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//
// Note:
// The length of path between two nodes is represented by the number of edges between them.
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
    void diameterOfNode(TreeNode* node,int& maxLen,int& leftLen, int& rightLen) {
        if (node == NULL) {
            return;
        }
        
        if (node->left) {
            int newLeftLen = 0;
            int newRightLen = 0;
            diameterOfNode(node->left, maxLen, newLeftLen, newRightLen);
            
            leftLen = max(newLeftLen + 1, newRightLen + 1);
        }
        
        if (node->right) {
            int newLeftLen = 0;
            int newRightLen = 0;
            diameterOfNode(node->right, maxLen, newLeftLen, newRightLen);
            
            rightLen = max(newLeftLen + 1, newRightLen + 1);
        }
        
        int curLen = leftLen + rightLen;
        maxLen = max(curLen, maxLen);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        int leftLen = 0;
        int rightLen = 0;
        diameterOfNode(root, maxLen, leftLen, rightLen);
        
        return maxLen;
    }
};
