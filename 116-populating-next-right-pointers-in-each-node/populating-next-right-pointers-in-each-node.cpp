// Given a binary tree
//
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
//
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
//
// 	You may only use constant extra space.
// 	Recursive approach is fine, implicit stack space does not count as extra space for this problem.
// 	You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//
//
// Example:
//
// Given the following perfect binary tree,
//
//
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
//
//
// After calling your function, the tree should look like:
//
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL
//
//


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    void structTree(TreeLinkNode* node,unordered_map<int,vector<TreeLinkNode*>>& tree,int level) {
        if (node == NULL) {
            return;
        }
        
        if (tree.find(level) == tree.end()) {
            tree[level] = {};
        }
        
        tree[level].push_back(node);
        structTree(node->left, tree, level + 1);
        structTree(node->right, tree, level + 1);
    }
public:
    void connect(TreeLinkNode* root) {
        unordered_map<int,vector<TreeLinkNode*>> tree = {};
        structTree(root, tree,0);
        
        for (auto kv : tree) {
            for (int i = 0; i < kv.second.size(); i++) {
                if (kv.second.size() == 0) {
                    break;
                }
                if (i == kv.second.size() - 1) {
                    kv.second[i]->next = NULL;
                }
                else {
                    kv.second[i]->next = kv.second[i + 1];
                }
            }
        }
    }
};
