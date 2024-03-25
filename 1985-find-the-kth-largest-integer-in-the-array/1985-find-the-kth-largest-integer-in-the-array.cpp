class NumStrMaxComparator {
public:
    bool operator() (string &a, string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
private:
    // Throwing runtime error: terminate called after throwing an instance of 'std::out_of_range' what():  stoi
    string mySolution(vector<string>& nums, int k) {
        priority_queue<int> maxHeap;
        
        for(string &x: nums) {
            maxHeap.push(stoi(x));
        }
        
        while(k-- > 1) {
            maxHeap.pop();
        }
        
        return to_string(maxHeap.top());
    }
    
    static bool numStrMaxComparator(string &a, string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // heapify cost O(N)
        make_heap(nums.begin(), nums.end(), NumStrMaxComparator());
        
        while (k-- > 1) {
            // Alternative way to call the comparator by defining as a static class method
            pop_heap(nums.begin(), nums.end(), numStrMaxComparator);
            nums.pop_back();
        }
        return nums.front();
    }
};