class Solution {
private:
    bool mySolution1(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i=0; i<cols; i++) {
            int r=0, c=i;
            unordered_set<int> s;
            while(r<rows && c<cols) {
                s.insert(matrix[r++][c++]);
                if(s.size() > 1) return false;
            }
        }
        for(int i=1; i<rows; i++) {
            int r=i, c=0;
            unordered_set<int> s;
            while(r<rows && c<cols) {
                s.insert(matrix[r++][c++]);
                if(s.size() > 1) return false;
            }
        }
        return true;
    }
    bool mySolution2(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int r=1; r<rows; r++) {
            for(int c=1; c<cols; c++) {
                if(matrix[r][c] != matrix[r-1][c-1]) return false;
            }
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // return mySolution1(matrix);
        return mySolution2(matrix);
    }
};