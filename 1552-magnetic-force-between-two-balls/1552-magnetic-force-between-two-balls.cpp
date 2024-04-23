class Solution {
private:
    bool canPlace(vector<int>& position, int distance, int m) {
        int ballCnt = 1, lastBall = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastBall >= distance) {
                lastBall = position[i];
                ballCnt++;
            }
            if (ballCnt == m) return true;
        }
        
        return false;
    }
    int solve(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();
        int low = 1;
        int high = position[n - 1] - position[0];
        
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            
            if (canPlace(position, mid, m)) low = mid + 1;
            else high = mid - 1;
        }
        
        return high;
    }
public:
    // Aggressive Cows
    // https://www.youtube.com/watch?v=R_Mfw4ew-Vo&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=18
    int maxDistance(vector<int>& position, int m) {
        return solve(position, m);
    }
};