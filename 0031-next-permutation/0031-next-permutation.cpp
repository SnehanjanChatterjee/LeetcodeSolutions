class Solution {
public:
    // https://www.youtube.com/watch?v=JDOXKqF60RQ&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=11
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        
        int n = nums.size(), index1 = -1, index2 = -1;
        
        // 1. Find index1 such that nums[i] < nums[i+1]
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index1 = i;
                // cout << "Found index1 = " << index1 << endl;
                break;
            }
        }
        
        // If initial array was in descending order, so index1 will be -1. 
        // So next permutation will be reverse of original array i.e sorted array
        if (index1 == -1) {
            sort(nums.begin(), nums.end());
            // cout << "Not Found index1 = " << index1 << ", so sorted array" << endl;
        } else {
            
            // 2. Find index2 toward right of index1 such that nums[i] > nums[index1]
            for(int i = n - 1; i > index1; i--) {
                if(nums[i] > nums[index1]) {
                    index2 = i;
                    // cout << "Found index2 = " << index2 << endl;
                    break;
                }
            }
            
            // 3. Swap nums[index1] & nums[index2]
            swap(nums[index1], nums[index2]);
            // cout<<"Swapped nums[index1]= "<<nums[index1]<<" & nums[index2]= "<<nums[index2]<< endl;

            // 4. Reverse all elements towards right of index1
            reverse(nums.begin() + (index1 + 1), nums.end());
            
        }
    }
};