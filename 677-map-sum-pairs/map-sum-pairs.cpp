//
// Implement a MapSum class with insert, and sum methods.
//
//
//
// For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
//
//
//
// For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
//
//
// Example 1:
//
// Input: insert("apple", 3), Output: Null
// Input: sum("ap"), Output: 3
// Input: insert("app", 2), Output: Null
// Input: sum("ap"), Output: 5
//
//
//


struct TrieNode {
    int val;
    unordered_map<char, TrieNode*> next;
    bool flag;
    
    TrieNode():val(0),flag(false){}
};

class MapSum {
private:
    TrieNode* root;
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next.count(word[i]) <= 0 ) {
                return false;
            }
            
            node = node->next[word[i]];
        }
        
        return node->flag;
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        bool isFind = this->search(key);
        TrieNode* node = root;
        
        for (int i = 0; i < key.length(); i++) {
            if (isFind) {
                node->val = val;
            }
            else {
                node->val += val;
            }

            if (node->next.count(key[i]) <= 0) {
                node->next[key[i]] = new TrieNode();
            }
            
            node = node->next[key[i]];
        }
        
        if (isFind) {
            node->val = val;
        }
        else {
            node->val += val;
        }
        
        node->flag = true;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        
        for (int i = 0; i < prefix.length(); i++) {

            if (node->next.count(prefix[i]) <= 0) {
                return 0;
            }
            
            node = node->next[prefix[i]];
        }

        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
