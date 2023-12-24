class Solution {
private:
    void static printVector(vector<int> &nums) {
        cout << "Sorted vector: ";
        for(int &x: nums) cout << x << " ";
        cout << endl;
    }
    
    bool existInSet(unordered_set<int> &ust, int &x) {
        return ust.find(x) != ust.end();
    }
    
    int solution1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // Remove duplicates from sorted vector
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int count = 0;
        int maxc = INT_MIN;
        
        // printVector(nums);
        
        for(int i=0;i<nums.size()-1;) {
            count = 1;
            if(nums[i] == nums[i+1]-1) {
                while(i<nums.size()-1 && nums[i] == nums[i+1]-1) {
                    i++;
                    count++;
                }
                maxc = max(maxc, count);
            }
            else {
                i++;
            }  
        }
        return maxc == INT_MIN ? 1 : maxc;
    }
    
    int solution2(vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int maxCnt = INT_MIN, cnt = 1;
        
        for(const int &x: ust) {
            int ele = x;
            int prevEle = x - 1;
            
            // If prev ele exist so x is not the starting ele of the sequence so ignore it.
            // Else it can be the starting element
            if (!existInSet(ust, prevEle)) {
                cnt = 1;
                while(existInSet(ust, ++ele)) {
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        
        return maxCnt;
    }
public:
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        // return solution1(nums);
        
        return solution2(nums);
        
    }
};