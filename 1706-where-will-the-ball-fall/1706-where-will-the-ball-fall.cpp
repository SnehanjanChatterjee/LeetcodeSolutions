class Solution {
private:
    int rows, cols;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        // When the ball actually leaves the grid, the column it's in will be the ans
        if(r == rows) return c;
        
        if(r<rows && c<cols && r>=0 && c>=0) {
            // If a cell is '\' then check if its right cell is also '\' or not. Otherwise it'll get stuck
            if(grid[r][c] == 1) {
                if(r<rows && c+1<cols && r>=0 && c+1>=0 && grid[r][c+1]==1) {
                    return dfs(r+1, c+1, grid);
                }
            }
            // If a cell is '/' then check if its left cell is also '/' or not. Otherwise it'll get stuck
            else if(grid[r][c] == -1) {
                if(r<rows && c-1<cols && r>=0 && c-1>=0 && grid[r][c-1]==-1) {
                    return dfs(r+1, c-1, grid);
                }
            }
        }
        
        return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<int> ans(cols, -1);
        for(int c=0; c<cols; c++) {
            ans[c] = dfs(0, c, grid);
        }
        return ans;
    }
};