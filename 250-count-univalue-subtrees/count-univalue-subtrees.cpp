// Given a binary tree, count the number of uni-value subtrees.
//
// A Uni-value subtree means all nodes of the subtree have the same value.
//
// Example :
//
//
// Input:  root = [5,1,5,5,5,null,5]
//
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
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
    void helper(TreeNode* node,bool& unique, int& count) {
        if (node == NULL) {
            unique = true;
            return;
        }
        
        bool leftUnique = false;
        helper(node->left, leftUnique, count);
        bool rightUnique = false;
        helper(node->right, rightUnique, count);
        
        if (leftUnique) {
            if (node->left) {
                leftUnique = node->left->val == node->val;
            }
        }
        
        if (rightUnique) {
            if (node->right) {
                rightUnique = node->right->val == node->val;
            }
        }
        
        if (leftUnique&&rightUnique) {
            count += 1;
            unique = true;
        }
        else {
            unique = false;
        }
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        bool unique = false;
        int count = 0;
        helper(root, unique, count);
        
        return count;
    }
};
