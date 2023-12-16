class Solution {
public:
    // DNF (Dutch National Flag) Sort
    // https://www.youtube.com/watch?v=tp8JIuCXBaU&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=6
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[high--], nums[mid]); // We could have got 0 from high's place so in next iteration we need to check that. So not moving mid.
            }
        }
    }
};