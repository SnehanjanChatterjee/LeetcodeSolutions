class Solution {
public:
    // Striver video: https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs&index=3
    int trap(vector<int>& height) {
        
        // Sliding window approach
        // t --> O(N)
        // s --> O(1)
        int n = height.size(); 
        int left = 0, right = n-1;
        int maxleft = 0, maxright = 0;
        int res = 0;
        
        while(left<=right){
            
            // So there exist an elevation of greater ht on right than current elevation
            if (height[left] <= height[right]) {

                if(height[left]>=maxleft) maxleft = height[left];
                else if(height[left]<maxleft) res += maxleft-height[left];
                
                left++;
            }
            else if (height[left] > height[right]) {

                if(height[right]>=maxright) maxright = height[right];
                else if(height[right]<maxright) res += maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};