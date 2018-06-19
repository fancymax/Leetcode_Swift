// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//


class Solution {
public:
    int numSquares(int n) {
        queue<int> queue;
        queue.push(n);
        
        unordered_map<int, int> dist = {};
        dist[n] = 0;

        while (!queue.empty()) {
            int key = queue.front();
            queue.pop();
            
            for (int i = 1; i <= n; i++) {
                int newKey = key - i * i;
                if ((newKey >= 0) && (dist.find(newKey) == dist.end())) {
                    queue.push(newKey);
                    dist[newKey] = dist[key] + 1;
                    
                    if (newKey == 0) {
                        return dist[newKey];
                    }
                }
            }
        }
        
        return 0;
    }
};
