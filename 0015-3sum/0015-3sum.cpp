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
    // https://www.youtube.com/watch?v=DhFh8Kw7ymk&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=21
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
                
            int low = i + 1;
            int high = n - 1;
            
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low < high && nums[low] == nums[low - 1]) low++;
                    while(low < high && nums[high] == nums[high + 1]) high--;
                }
                else if(sum < 0) low++;
                else if(sum > 0) high--;
            }
            // printVector(result);
        }

        return result;
        
    }
};