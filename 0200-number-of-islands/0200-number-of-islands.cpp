class Solution {
private:
    vector<int> dRow = {-1, 0, +1, 0};
    vector<int> dCol = {0, +1, 0, -1};
    
    void dfs(int row, int col, int rows, int cols, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        if(row<0 || col<0 || row==rows || col==cols) return;
        
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if((nRow>=0 && nCol>=0 && nRow<rows && nCol<cols) && (grid[nRow][nCol]=='1' && vis[nRow][nCol]==-1)) {
                dfs(nRow, nCol, rows, cols, grid, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(rows, vector<int> (cols, -1));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]=='1' && vis[i][j]==-1) {
                    dfs(i, j, rows, cols, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};