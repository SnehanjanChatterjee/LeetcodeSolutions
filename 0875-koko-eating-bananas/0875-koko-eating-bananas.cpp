class Solution {
private:
    int hoursToEat(vector<int>& piles, int k, int h) {
        int ans = 0;
        for(auto &x: piles) {
            ans += ceil((double)x / (double)k);
            if (ans > h) return ans; // int overflow occured. So to prevent that return if ans is already over h
        }
        
        return ans;
    }
public:
    // https://www.youtube.com/watch?v=qyfekrNni90&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=13
    int minEatingSpeed(vector<int>& piles, int h) {
        // Here we are doing binary search on answer space (not in the given input space)
        // The ans can lie b/w 1 and max element of array ->
        // Total time taken to eat maxElement bananas per hour, will be same as time taken to eat maxElement+1 bananas per hour.
        // So max search space can be maxElement of array.
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            
            if (hoursToEat(piles, mid, h) <= h) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
};