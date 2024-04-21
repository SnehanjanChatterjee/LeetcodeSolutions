class Solution {
private:
    vector<int> dRow = {-1, 0, +1, 0};
    vector<int> dCol = {0, +1, 0, -1};
    
    void printVector(vector<int> &group) {
        for (auto &x: group) cout << x << ' ';
        cout << endl;
    }
    
    bool isWithinGrid(int row, int col, int rows, int cols) {
        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }
    
    void dfs(int row, int col, int rows, int cols, vector<vector<int>>& land, vector<vector<int>>& vis, vector<int>& group) {
        if (!isWithinGrid(row, col, rows, cols)) return;
        
        vis[row][col] = 1;
        
        // Last cell
        if (row == (rows - 1) && col == (cols - 1)) {
            group.push_back(row);
            group.push_back(col);
        }
        
        // Both right and bottom exist but both are 0
        else if (col + 1 < cols && land[row][col + 1] == 0 && row + 1 < rows && land[row + 1][col] == 0) {
            group.push_back(row);
            group.push_back(col);
        }
        
        // Bottom doesn't exist & right is 0        
        else if (row == rows - 1 && land[row][col + 1] == 0) {
            group.push_back(row);
            group.push_back(col);
        }
        
        // Right doesn't exist & bottom is 0
        else if (col == cols - 1 && land[row + 1][col] == 0) {
            group.push_back(row);
            group.push_back(col);
        }
        
        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (isWithinGrid(nRow, nCol, rows, cols) && (land[nRow][nCol] == 1 && vis[nRow][nCol] == 0)) {
                dfs(nRow, nCol, rows, cols, land, vis, group);
            }
        }
    }
    // Ref: https://www.youtube.com/watch?v=dCNPK13QCP8
    vector<vector<int>> mySolution(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (land[row][col] == 1 && vis[row][col] == 0) {
                    vector<int> group;
                    
                    group.push_back(row);
                    group.push_back(col);
                    
                    dfs(row, col, rows, cols, land, vis, group);
                    
                    ans.push_back(group);
                }
            }
        }
        
        return ans;
    }
    
    // https://leetcode.com/problems/find-all-groups-of-farmland/discuss/1444086/C%2B%2B-Straight-forward-approach-no-super-mind-(Commented)
    vector<vector<int>> discussionSolution(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                //We have to deal with 1s only
                if(land[i][j] == 0) continue;

                //Find right most column of rectangle (see the image below)
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }

                //Find bottom most row of rectangle (see the image below)
                int r2 = i;
                while(r2 < m && land[r2][j] == 1) {
                    r2++;
                }
                
                //Then you can find bottom right most of rectangle
                c1 = c1==0 ? c1 : c1-1;
                r2 = r2==0 ? r2 : r2-1;

                //Use them as your answer
                //{r1, c1} = {i, j}
                //{r2, c2} = {r2, c1}
                result.push_back({i, j, r2, c1});
                
                //Now, mark the covered land with 0 so that you don't consider them later
                for(int k = i; k<=r2; k++) {
                    for(int l = j; l<=c1; l++) {
                        land[k][l] = 0;
                    }
                }
                
            }
        }
        return result;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // return mySolution(land);
        
        return discussionSolution(land);
    }
};