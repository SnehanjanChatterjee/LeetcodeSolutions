class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i=0,j=0;
        deque<int> dq;
        vector<int> v;
        int n=arr.size();
        
        while(j<n) {
            // Deque hold all could be max values (where dq.front() is current max value
            // So before pushing any element I am checking if current last element is smaller than that or not.
            // If so remove it. It wont be a candidate for max element
            if(!dq.empty() && dq.back() < arr[j]) {
                while(!dq.empty() && dq.back() < arr[j]) {
                    dq.pop_back();
                }
            }
            dq.push_back(arr[j]);
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k) {
                // Calculate
                v.push_back(dq.front());
                if(arr[i] == dq.front())
                    dq.pop_front();
                
                i++;j++;
            }
        }
        return v;
    }
};