class Solution {
public:
    // Similar to Leaders in an array
    // https://www.youtube.com/watch?v=cHrH9CQ8pmY&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=12
    vector<int> replaceElements(vector<int>& arr) {
        int maxElement = INT_MIN, n=arr.size();
        
        for(int i=n-1; i>=0; i--) {
            maxElement = max(maxElement, arr[i]);
            arr[i] = maxElement;
        }
        
        for(int i=0; i<n-1; i++) {
            arr[i] = arr[i+1];
        }
        
        arr[n-1] = -1;
        
        return arr;
    }
};