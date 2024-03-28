class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxLength = INT_MIN;
        
        // Sliding window
        while(j < n) {
            ump[nums[j]]++;
            
            
            // if(ump[nums[j]] <= k) { // If after considering current char count is within limit, calculate length
            //     maxLength = max(maxLength, (j - i + 1));
            //     // cout<<"If: ump["<<nums[j]<<"] = "<<ump[nums[j]]<<" maxLength = "<<maxLength<<endl;
            // } else if(ump[nums[j]] > k) {
            //     // cout<<"else: ump["<<nums[i]<<"] = "<<ump[nums[i]]<<endl;
            //     if(nums[i] == nums[j]) {
            //         while(i<n && ump[nums[i]] > k) { // Till freq is not within limits keep removing ith element
            //             ump[nums[i]]--;
            //             // cout<<"while: ump["<<nums[i]<<"] = "<<ump[nums[i]]<<endl;
            //             if(ump[nums[i]] == 0) ump.erase(nums[i]);
            //             i++;
            //         }
            //     } else {
            //         ump.clear();
            //         i = j;
            //         ump[nums[i]]++;
            //     }
            // }
            
            if(ump[nums[j]] > k){
                while(i<j && ump[nums[j]] > k) {
                    ump[nums[i]]--;
                    i++;
                }
            }
            
            maxLength = max(maxLength, (j - i + 1));
            
            j++;
        }
        
        return maxLength;
    }
};