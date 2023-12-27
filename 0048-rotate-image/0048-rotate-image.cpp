class Solution {
public:
    // Expl: https://www.youtube.com/watch?v=Z0R2u6gd3GU&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=15
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i<rows-1; i++) {
            for(int j=i+1; j<cols; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(vector<int> &x: matrix) {
            reverse(x.begin(), x.end());
        }
    }
};