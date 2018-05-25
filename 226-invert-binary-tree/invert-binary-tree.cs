// Invert a binary tree.
//
// Example:
//
// Input:
//
//
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
//
// Output:
//
//
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
//
// Trivia:
// This problem was inspired by this original tweet by Max Howell:
//
// Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
//


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode InvertTree(TreeNode root) {
        if(root == null)
        {
            return root;
        }
        else
        {
            TreeNode temp = InvertTree(root.left);
            root.left = InvertTree(root.right);
            root.right = temp;
            return root;
        }
    }
}
