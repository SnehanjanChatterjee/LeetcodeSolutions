class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        int ans = 1;
        
        for(int i=0; i<rows; i++) {
            unordered_map<double, set<pair<int, int>>> ump;
            
            for(int j=0; j<rows; j++) {
                if(i != j) {
                    int x1 = points[i][0], x2 = points[j][0];
                    int y1 = points[i][1], y2 = points[j][1];
                    double dx = (x1 - x2);
                    double dy = (y1 - y2);
                    double slope = (dx == 0) ? INT_MAX : (double)(dy / dx);
                                 
                    ump[slope].insert({x1, y1});
                    ump[slope].insert({x2, y2});         
                }
            }
            
            for(auto &itr: ump) {
                int setSize = itr.second.size();
                ans = max(ans, setSize);
            }
        }
        
        return ans;
    }
};