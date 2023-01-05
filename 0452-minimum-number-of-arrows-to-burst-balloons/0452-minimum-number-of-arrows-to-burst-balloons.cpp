class Solution {
private:
    static bool myComp(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), myComp);
        int ans = 0, x = 0;
        int rows = points.size();
        
        for(int i=0; i<rows; i++) {
            if(ans == 0 || points[i][0] > x) {
                ans++;
                x = points[i][1];
            }
        }
        
        return ans;
    }
};