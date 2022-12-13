class Solution {
private:
    bool withinMatrix(int r, int c, int rows, int cols) {
        return r>=0 && r<rows && c>=0 && c<cols;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int r=1; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                int minSum = INT_MAX;
                if(withinMatrix(r-1, c-1, rows, cols)) {
                    minSum = min(minSum, matrix[r][c] + matrix[r-1][c-1]);
                }
                if(withinMatrix(r-1, c, rows, cols)) {
                    minSum = min(minSum, matrix[r][c] + matrix[r-1][c]);
                }
                if(withinMatrix(r-1, c+1, rows, cols)) {
                    minSum = min(minSum, matrix[r][c] + matrix[r-1][c+1]);
                }
                matrix[r][c] = minSum;
            }
        }
        
        return *min_element(matrix[rows-1].begin(), matrix[rows-1].end());
    }
};