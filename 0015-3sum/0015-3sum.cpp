class Solution {
public:
    void printVector(vector<vector<int>>& nums) {
        cout<< "Result vector:" << endl;
        for(vector<int> &x: nums) {
            for(int &y: x) {
                cout<<y<<" ";
            }
            cout<<endl;
        }
        cout << endl;
    }
    
    // Optimal
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
                
            int low = i + 1;
            int high = n - 1;
            int sum = 0 - nums[i];
            while(low < high) {
                if(nums[low] + nums[high] == sum) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum) low++;
                else if(nums[low] + nums[high] > sum) high--;
            }
            // printVector(result);
        }

        return result;
        
    }
};