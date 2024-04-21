class Solution {
private:
    int totalDays(vector<int>& bloomDay, int day, int m, int k) {
        int dayCnt = 0, bouquetsCnt = 0;
        for(int &x: bloomDay) {
            if (x <= day) dayCnt++;
            else {
                bouquetsCnt += (dayCnt / k);
                dayCnt = 0;
            }
            
            if (bouquetsCnt >= m) return bouquetsCnt; // Added this line to prevent int overflow as further adding not required
        }
        bouquetsCnt += (dayCnt / k);
        
        return bouquetsCnt;
    }
    
    int striver_BruteForce(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size()) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        for (int i=low; i <= high; i++) {
            if (totalDays(bloomDay, i, m, k) >= m) return i;
        }
        return -1;
    }
    
    int striver_Optimal(vector<int>& bloomDay, int m, int k) {
        if (1LL* m * 1LL * k > bloomDay.size()) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (totalDays(bloomDay, mid, m, k) >= m) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // return striver_BruteForce(bloomDay, m, k);
        return striver_Optimal(bloomDay, m, k);
    }
};