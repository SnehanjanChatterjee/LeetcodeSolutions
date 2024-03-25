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
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        make_heap(nums.begin(), nums.end(), NumStrMaxComparator()); // heapify cost O(N)
        while (k-- > 1) {
            pop_heap(nums.begin(), nums.end(), NumStrMaxComparator());
            nums.pop_back();
        }
        return nums.front();
    }
};