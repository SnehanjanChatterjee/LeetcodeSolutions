class Solution {
private:
    // https://www.youtube.com/watch?v=bR7mQgwQ_o8&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=18
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //inserting the 1st element

        //calculate the rest of the elements:
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<int> solution2(int n) {
        return generateRow(n);
    }
    
    vector<int> mySolution(int n) {
        vector<vector<int>> ans(n);
        
        for(int i=0; i<n; i++) {
            ans[i].resize(i+1);
            for(int j=0; j<i+1; j++) {
                if(j == 0 || j == i) ans[i][j] = 1;
                else ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans[n - 1];
    }
public:
    vector<int> getRow(int rowIndex) {
        return mySolution(rowIndex + 1);
        
        // return solution2(rowIndex + 1);
    }
};