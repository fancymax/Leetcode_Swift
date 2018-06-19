// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time.
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return 0 if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

 unordered_map<string, int> dist = {};
        for (auto word : wordList) {
            dist[word] = -1;
        }
        dist[beginWord] = 1;
        queue<string> queue;
        queue.push(beginWord);
        
        while (!queue.empty()) {
            string key = queue.front();
            queue.pop();
            
            for (int i = 0; i < key.size(); i++) {
                string originKey = key;
                for (char c = 'a'; c < 'a' + 26; c++) {
                    key[i] = c;
                    if (dist[key]) {
//                        cout << key << " = " << dist[key] << "\n";
                        if (dist[key] ==  -1) {
                            queue.push(key);
                            dist[key] = dist[originKey] + 1;
//                            cout << "-- " << key << " = " << dist[key] << "\n";
                        }
                    }
                }
                key = originKey;
            }
        }
        
        if (!dist[endWord]) {
            return 0;
        }
        
        if (dist[endWord] == -1) {
            return 0;
        }
        else  {
            return dist[endWord];
        }
    }
};
