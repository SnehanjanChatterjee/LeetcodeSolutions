class Solution {
private:
    // TC -> O(N^2) for all cases
    // SC -> O(1)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#42-selection-sort
    // 2. https://www.youtube.com/watch?v=HGk_ypEuS24
    void selectionSort(vector<int>& nums) {
        int smallIndex = 0, n = nums.size();
        for(int  i= 0; i < n-1; i++) {
            smallIndex = i;
            
            for(int j = i+1; j < n; j++) {
                if(nums[j] < nums[smallIndex]) {
                    smallIndex = j;
                }
            }
            
            if(smallIndex != i) { // i.e we have found a smaller element
                swap(nums[i], nums[smallIndex]);
            }
        }
    }
    
    // TC -> O(N^2) for the worst and average cases and O(N) for the best case (Already sorted)
    // SC -> O(1)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#43-bubble-sort
    // 2. https://www.youtube.com/watch?v=HGk_ypEuS24
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int didSwap = 0;
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j+1]);
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }
    }
    
    // TC -> O(N^2) for the worst and average cases and O(N) for the best case (Already sorted)
    // SC -> O(1)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#41-insertion-sort
    // 2. https://www.youtube.com/watch?v=HGk_ypEuS24
    void insertionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n - 1; i++) {
            int j = i;
            while (j > 0 && nums[j - 1] > nums[j]) {
                swap(nums[j-1], nums[j]);
                j--;
            }
        }
    }
    
    // TC -> O(NlogN) for the all cases
    // SC -> O(N)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#44-merge-sort
    // 2. // TC -> O(NlogN) for the all cases
    // SC -> O(N)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#44-merge-sort
    // 2. https://www.youtube.com/watch?v=HGk_ypEuS24
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2 ;
        mergeSort(nums, low, mid);  // left half
        mergeSort(nums, mid + 1, high); // right half
        merge(nums, low, mid, high);  // merging sorted halves
    }
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of nums
        int right = mid + 1;   // starting index of right half of nums

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Transfering all elements from temp array to nums
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    
    // TC -> O(NlogN) for the best and average cases and O(N^2) for the worst case (Already sorted)
    // SC -> O(N)
    // Ref -> 
    // 1. https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#45-quicksort
    // 2. https://www.youtube.com/watch?v=WIrA4YexLRQ
    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pIndex = partition(nums, low, high);
            quickSort(nums, low, pIndex - 1);
            quickSort(nums, pIndex + 1, high);
        }
    }
    int partition(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (nums[i] <= pivot && i <= high - 1) {
                i++;
            }

            while (nums[j] > pivot && j >= low + 1) {
                j--;
            }
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        // selectionSort(nums);
        // bubbleSort(nums);
        // insertionSort(nums);
        mergeSort(nums, 0, nums.size() - 1);
        // quickSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};