class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
              if (board[i][j] != '.') {
                  if (isValid(board, i, j, board[i][j]) == false) {
                    return false;
                  }
              }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> & board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if(i != row)  
                if (board[i][col] == c)
                    return false;
            if(i != col)
              if (board[row][i] == c)
                  return false;
            if(((3 * (row / 3) + i / 3) != row) && ((3 * (col / 3) + i % 3) != col))
                if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                    return false;
        }
        return true;
    }

};