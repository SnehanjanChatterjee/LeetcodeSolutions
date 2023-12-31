class Solution {
private:
    // Not using any variable
    vector<vector<int>> soln1(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n=intervals.size();
        
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        
        for(int i=0;i<n;i++) {
            if(merged.back()[1] >= intervals[i][0]) {
                merged.back()[0] = min(intervals[i][0], merged.back()[0]);
                merged.back()[1] = max(intervals[i][1], merged.back()[1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
    
    // Using variable
    vector<vector<int>> soln2(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1], n = intervals.size();
        
        for(int i=1; i<n; i++) {
            if (intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        
        return ans;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // return soln1(intervals);
        
        return soln2(intervals);
    }
};