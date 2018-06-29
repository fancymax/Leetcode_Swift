// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//
//


class Solution {
private:
    void DFS(vector<vector<char>>& grid,int i, int j, bool* visited,int row, int col) {
        *(visited + i*col + j) = true;
        if (j+1 < col) {
            if ((grid[i][j+1] == '1') && (*(visited + i*col + j+1)) == false) {
                DFS(grid, i, j+1, visited, row, col);
            }
        }
        if (i+1 < row) {
            if ((grid[i+1][j] == '1') && (*(visited + (i+1)*col + j)) == false) {
                DFS(grid, i+1, j, visited, row, col);
            }
        }
        
        if (j-1 >= 0) {
            if ((grid[i][j-1] == '1') && (*(visited + i*col + j-1)) == false) {
                DFS(grid, i, j-1, visited, row, col);
            }
        }
        if (i-1 >= 0) {
            if ((grid[i-1][j] == '1') && (*(visited + (i-1)*col + j)) == false) {
                DFS(grid, i-1, j, visited, row, col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();
        if (col == 0) {
            return 0;
        }
        bool visited[row][col];
        memset(visited, false, sizeof(visited));
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((!visited[i][j]) && (grid[i][j] == '1')) {
                    count += 1;
                    DFS(grid, i, j, (bool *)visited, row, col);
                }
            }
        }
        
        return count;
    }
};
