// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// Example: 
//
//
// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"
//
//
// Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        queue<TreeNode*> remainNodes;
        remainNodes.push(root);
        
        while (!remainNodes.empty()) {
            TreeNode* node = remainNodes.front();
            remainNodes.pop();
            
            if (node == NULL) {
                if (remainNodes.size() != 0) {
                    res.append("null");
                    res.append(",");
                }
            }
            else {
                res.append(to_string(node->val));
                res.append(",");
                
                remainNodes.push(node->left);
                remainNodes.push(node->right);
            }
        }
        
        if (res[res.size() - 1] == ',') {
            res.replace(res.size() - 1, res.size() - 1, "]");
        }
        else {
            res.push_back(']');
        }

        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.erase(0,1);
        data.erase(data.size() - 1,1);
        
        if (data == "") {
            return  NULL;
        }
        
        queue<TreeNode*> nodes;
        int pos = 0;
        while (pos < data.size()) {
            int next = data.find_first_of(',',pos);
            if (next == string::npos) {
                next = data.size();
            }
            string val = data.substr(pos,next - pos);
            if (val == "null") {
                nodes.push(NULL);
            }
            else {
                nodes.push(new TreeNode(stoi(val)));
            }
            
            pos = next + 1;
        }
        
        TreeNode* root = nodes.front();
        nodes.pop();
        
        queue<TreeNode*> remainNodes;
        remainNodes.push(root);
        
        while (!remainNodes.empty()) {
            TreeNode* node = remainNodes.front();
            remainNodes.pop();
            
            if (node == NULL) {
                continue;
            }
            
            if (nodes.empty()) {
                node->left = NULL;
            }
            else {
                node->left = nodes.front();
                nodes.pop();
                remainNodes.push(node->left);
            }
            if (nodes.empty()) {
                node->right = NULL;
            }
            else {
                node->right = nodes.front();
                nodes.pop();
                remainNodes.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
