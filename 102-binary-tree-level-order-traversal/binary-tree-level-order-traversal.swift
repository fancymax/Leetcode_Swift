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
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
            var totalLevels = [[Int]]()
    
    var levelNodes = [TreeNode]()
    
    if let rootNode = root {
        levelNodes.append(rootNode)
    }
    else {
        return totalLevels
    }
    
    while levelNodes.count != 0 {
        var nextLevelNodes = [TreeNode]()
        for node in levelNodes {
            if let leftNode = node.left {
                nextLevelNodes.append(leftNode)
            }
            if let rightNode = node.right {
                nextLevelNodes.append(rightNode)
            }
        }
        totalLevels.append(levelNodes.map{ $0.val })
        levelNodes = nextLevelNodes
    }
    
    return totalLevels
    }
}
