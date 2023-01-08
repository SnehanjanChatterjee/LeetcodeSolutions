class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // unordered_map<double, set<pair<int, int>>> ump;
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
                                 
                    // if(slope == -0) slope = 0;
                    // ump[slope]++;
                    ump[slope].insert({x1, y1});
                    ump[slope].insert({x2, y2});
                                 
                    // cout<<"B/W ("<<points[i][0]<<","<< points[i][1]<<") && ("<<points[j][0]<<","<<points[j][1]<<") xDiff = "<<xDiff<<" yDiff = "<<yDiff<<" slope is "<<slope<<endl;
                                 
                }
            }
            
            for(auto itr: ump) {
                int setSize = itr.second.size();
                ans = max(ans, setSize);
                // cout<<"For slope = "<<itr.first<<" coordinates are: "<<endl;
                // for(auto x: itr.second) cout << "(" << x.first <<","<< x.second << ")" << endl;
            }
        }
        
        return ans;
    }
};