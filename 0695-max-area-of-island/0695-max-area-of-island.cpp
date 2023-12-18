class Solution {
private:
    void dfs(int row, int col, int &rows, int &cols, vector<vector<int>>& grid, int &sum) {
        if(row >= rows || row < 0 || col >= cols || col < 0) return;
        
        grid[row][col] = 0;
        
        if((row < rows && row >= 0 && col-1 < cols && col-1 >= 0) && grid[row][col - 1] == 1) {
            sum++;
            dfs(row, col-1, rows, cols, grid, sum);
        }
        if((row < rows && row >= 0 && col+1 < cols && col+1 >= 0) && grid[row][col + 1] == 1) {
            sum++;
            dfs(row, col+1, rows, cols, grid, sum);
        }
        if((row-1 < rows && row-1 >= 0 && col < cols && col >= 0) && grid[row-1][col] == 1) {
            sum++;
            dfs(row-1, col, rows, cols, grid, sum);
        }
        if((row+1 < rows && row+1 >= 0 && col < cols && col >= 0) && grid[row+1][col] == 1) {
            sum++;
            dfs(row+1, col, rows, cols, grid, sum);
        }
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSum = INT_MIN;
        int rows = grid.size(), cols = grid[0].size();
        
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(grid[row][col] == 1) {
                    int sum = 1;
                    dfs(row, col, rows, cols, grid, sum);
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum == INT_MIN ? 0 : maxSum;
    }
};