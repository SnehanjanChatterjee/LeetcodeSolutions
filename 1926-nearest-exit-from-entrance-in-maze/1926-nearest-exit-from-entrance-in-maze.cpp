class Solution {
private:
    bool isExitCell(int &row, int &col, int &rows, int &cols, vector<vector<char>>& maze) {
        return (row==0 || col==0 || row==rows-1 || col==cols-1);
    }
    bool isValidCell(int &row, int &col, int &rows, int &cols, vector<vector<char>>& maze, vector<vector<int>>& vis) {
        return ((row>=0 && col>=0 && row<rows && col<cols) && vis[row][col] == -1 && maze[row][col] == '.');
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols, -1));
        int steps = 0;
        // 4 directions are UP: (row-1, col+0), RIGHT: (row+0, col+1), BOTTOM: (row+1, col+0), LEFT: (row+0, col-1)
        int delRow[] = {-1, 0, 1, 0}; // All 4 possible changes to row value
        int delCol[] = {0, 1, 0, -1}; // All 4 possible changes to col value
        queue<pair<int, int>> q;
        
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        while(!q.empty()) {
            int size = q.size();
            steps++;
            while(size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    if(isValidCell(nRow, nCol, rows, cols, maze, vis)) {
                        if(isExitCell(nRow, nCol, rows, cols, maze)) return steps;
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        return -1;
    }
};