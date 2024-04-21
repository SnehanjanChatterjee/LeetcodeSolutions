class Solution {
private:
    int totalDaysTaken(vector<int>& weights, int dayCapacity) {
        int daysCnt = 1;
        int load = 0;
        
        for(int &x: weights) {
            if (load + x > dayCapacity) daysCnt++, load = x; // If load exceeds day capacity, we move to next day
            else load += x;
        }
        
        return daysCnt;
    }
    
    // TC -> O(N * (sum of araay - max of array))
    // SC -> O(1)
    int striver_BruteForce(int low, int high, vector<int>& weights, int days) {        
        for (int i = low; i <= high; i++) {
            if (totalDaysTaken(weights, i) <= days) return i;
        }
        return -1;
    }
    
    // TC -> O(N * log(sum of araay - max of array))
    // SC -> O(1)
    int striver_Optimal(int low, int high, vector<int>& weights, int days) {       
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (totalDaysTaken(weights, mid) <= days) high = mid - 1; //  We need lower capacity so search for lower now
            else low = mid + 1;
        }
        
        return low;
    }
public:
    // https://www.youtube.com/watch?v=MG-Ac4TAvTY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=16
    int shipWithinDays(vector<int>& weights, int days) {
        // Here min capacity can be max element of ship
        // Max capacity can be sum of all loads i.e I can load all in one day i.e min days
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        // return striver_BruteForce(low, high, weights, days);
        return striver_Optimal(low, high, weights, days);
    }
};