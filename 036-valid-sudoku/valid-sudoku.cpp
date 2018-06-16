// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//
// 	Each row must contain the digits 1-9 without repetition.
// 	Each column must contain the digits 1-9 without repetition.
// 	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//
//
// A partially filled sudoku which is valid.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
// Example 1:
//
//
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
//
// Example 2:
//
//
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being 
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//
// Note:
//
//
// 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// 	Only the filled cells need to be validated according to the mentioned rules.
// 	The given board contain only digits 1-9 and the character '.'.
// 	The given board size is always 9x9.
//
//


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //use hashTable
        //Step1: loop each row and col and every sub 3*3 box
        //check hashTable if digit duplication
        set<char> validationSet = {};
        
        for (int i = 0; i < board.size(); i++) {
            validationSet.clear();
            //every row
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!validationSet.emplace(board[i][j]).second) {
                    return  false;
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            validationSet.clear();
            //every col
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (!validationSet.emplace(board[j][i]).second) {
                    return  false;
                }
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                validationSet.clear();
                auto row = i*3;
                auto col = j*3;
                for (int a = row; a < row + 3; a++) {
                    for (int b = col;b < col + 3; b++) {
                        if (board[a][b] == '.') {
                            continue;
                        }
                        if (!validationSet.emplace(board[a][b]).second) {
                            return  false;
                        }
                    }
                }
                
            }
            
        }
        
        return true;
    }
};
