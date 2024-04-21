class Solution {
private:
    double bruteForce(vector<int>& nums1, vector<int>& nums2) {
        copy(nums2.begin(), nums2.end(), back_inserter(nums1)); // Insert nums2 into nums1
        
        int n1 = nums1.size();
        
         if(n1 % 2 == 0) {
            nth_element(nums1.begin(), nums1.begin() + n1/2, nums1.end()); // Finding median using nth_element
            int ans1 = nums1[n1/2];
            nth_element(nums1.begin(), nums1.begin() + n1/2 - 1, nums1.end());
            int ans2 = nums1[n1/2 - 1];
            return (ans1 + ans2) / 2.0;
        } else {
            nth_element(nums1.begin(), nums1.begin() + n1/2, nums1.end());
            return nums1[n1/2];
        }
    }
    
    // https://www.youtube.com/watch?v=F9c7LpRZWVQ&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=23
    // TC -> O(log(min(n1,n2)))
    // SC -> O(1)
    double optimalSolution(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // if n1 is bigger swap the arrays:
        if (n1 > n2) return optimalSolution(nums2, nums1);

        int n = n1 + n2; // total length
        int left = (n1 + n2 + 1) / 2; // How many elements should be there in the new hypothetical merged array's left half
        
        // apply binary search:
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            
            // calculate l1, l2, r1 and r2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            // eliminate the halves:
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0; //dummy statement
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return bruteForce(nums1, nums2);
        return optimalSolution(nums1, nums2);
    }
};