class Solution {
private:
    // TC -> O(N)
    // SC -> O(1)
    int striver_BruteForce(vector<int>& arr, int k) {
        // Array elements can lie b/w 1 and 1000
        // If there is an element x whose value is <= k, that means x is taking a place in between 1 & kth missing no. So k++
        // E.g [5,7,10,12], k = 6, Missing Nos = [1, 2, 3, 4, 5(not missing but takes plae in between), 6].
        // So 6ht missing will be k + 1 = 7.
        for (const int &x : arr) {
            if(x <= k) k++;
            else break;
        }
        return k;
    }
    
    // TC -> O(logN)
    // SC -> O(N)
    int striver_Optimal(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1, mid, missing;
        
        while (low <= high) {
            mid = low + ((high - low) / 2);
            missing = arr[mid] - (mid + 1);
            
            if (missing < k) low = mid + 1;
            else high = mid - 1;
        }
        
        // ans -> arr[high] + some more value
        // ans -> arr[high] + (k - missing)
        // ans -> arr[high] + (k - (arr[high] - (high + 1)))
        // ans -> arr[high] + k - arr[high] + high + 1
        // ans -> (high + 1) + k
        // ans -> low + k
        return low + k;
    }
public:
    // https://www.youtube.com/watch?v=uZ0N_hZpyps&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=17
    int findKthPositive(vector<int>& arr, int k) {
        // return striver_BruteForce(arr, k);
        return striver_Optimal(arr, k);
    }
};