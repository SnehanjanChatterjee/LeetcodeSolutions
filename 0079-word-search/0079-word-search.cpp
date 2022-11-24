class Solution {
private:
    // 4 directions are UP: (row-1, col+0), RIGHT: (row+0, col+1), BOTTOM: (row+1, col+0), LEFT: (row+0, col-1)
    int delRow[4] = {-1, 0, 1, 0}; // All 4 possible changes to row value
    int delCol[4] = {0, 1, 0, -1}; // All 4 possible changes to col value
    int rows;
    int cols;
    string reqWord;

    bool isValidCell(int &row, int &col) {
        return (row>=0 && col>=0 && row<rows && col<cols);
    }
    
    bool dfs(int row, int col, int wordIndex, vector<vector<char>>& board) {
        if(wordIndex == reqWord.size()) return true;
        if(!isValidCell(row, col) || board[row][col] != reqWord[wordIndex]) return false;

        board[row][col] = '-1';

        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(dfs(nRow, nCol, wordIndex + 1, board)) return true;
        }

        board[row][col] = reqWord[wordIndex];

        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return false;

        rows = board.size();
        cols = board[0].size();
        reqWord = word;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == reqWord[0] && dfs(i, j, 0, board)) return true;
            }
        }
        
        return false;
    }
};