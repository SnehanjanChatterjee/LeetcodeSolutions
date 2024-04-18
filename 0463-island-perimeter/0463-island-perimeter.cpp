class Solution {
private:
    bool isOutOfGrid(int row, int col, int &rows, int &cols) {
        return (row < 0 || row >= rows || col < 0 || col >= cols);
    }
    bool isWater(int row, int col, vector<vector<int>>& grid) {
        return grid[row][col] == 0;
    }
    void dfs(int row, int col, int &rows, int &cols, int &parameter, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(isOutOfGrid(row, col, rows, cols)) return;
        
        vis[row][col] = 1;
        
        if(isOutOfGrid(row - 1, col, rows, cols) || isWater(row - 1, col, grid)) parameter++;
        else if(!vis[row - 1][col]) dfs(row - 1, col, rows, cols, parameter, grid, vis);
        
        if(isOutOfGrid(row, col - 1, rows, cols) || isWater(row, col - 1, grid)) parameter++;
        else if(!vis[row][col - 1]) dfs(row, col - 1, rows, cols, parameter, grid, vis);
        
        if(isOutOfGrid(row + 1, col, rows, cols) || isWater(row + 1, col, grid)) parameter++;
        else if(!vis[row + 1][col]) dfs(row + 1, col, rows, cols, parameter, grid, vis);
        
        if(isOutOfGrid(row, col + 1, rows, cols) || isWater(row, col + 1, grid)) parameter++;
        else if(!vis[row][col + 1]) dfs(row, col + 1, rows, cols, parameter, grid, vis);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int parameter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        bool isIslandFound = false;
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(grid[row][col]) {
                    dfs(row, col, rows, cols, parameter, grid, vis);
                    isIslandFound = true;
                    break;
                }
            }
            if(isIslandFound) break;
        }
        
        return parameter;
    }
};