class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        
        int n = nums.size();
        int index1=-1, index2=-1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                index1 = i;
                // cout << "Found index1 = " << index1 << endl;
                break;
            }
        }
        if (index1 == -1) {
            sort(nums.begin(), nums.end());
            // cout << "Not Found index1 = " << index1 << ", so sorted array" << endl;
        } else {
            for(int i=n-1; i>index1; i--) {
                if(nums[i]>nums[index1]) {
                    index2 = i;
                    // cout << "Found index2 = " << index2 << endl;
                    break;
                }
            }
            
            int temp = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = temp;

            // cout<<"Swapped nums[index1]= "<<nums[index1]<<" & nums[index2]= "<<nums[index2]<< endl;

            for(int i=index1+1, j=n-1;i<j;i++, j--) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                // cout<<"Swapped nums[i]= "<<nums[i]<<" & nums[j]= "<<nums[j]<< endl;
            }
            
        }
    }
};