class Solution {
private:
    vector<int> hashingSoln(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int &x: nums) {
            mp[x]++;
        }
        vector<int> v;
        
        int majorityCount = floor(nums.size() / 3);
        
        for(auto &x: mp) {
            if(x.second > majorityCount) {
                v.push_back(x.first);
            }
        }
        
        return v;
    }
    vector<int> MooresVotingAlgo(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1 = 0, ele2 = 0, n = nums.size();
        vector<int> ans;
        
        // Find candidates that can be majority element
        for(int &x: nums) {
            if(cnt1 == 0 && x != ele2) {
                ele1 = x;
                cnt1 = 1;
            } else if(cnt2 == 0 && x != ele1) {
                ele2 = x;
                cnt2 = 1;
            } else if(ele1 == x) {
                cnt1++;
            } else if(ele2 == x) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Check if they are actually majority element
        cnt1 = 0, cnt2 = 0;
        for(int &x: nums) {
            if(x == ele1) cnt1++;
            else if(x == ele2) cnt2++;
        }
        
        // Add all final elements to answer vector
        int majorityCnt = floor(n/3);
        if(cnt1 > majorityCnt) ans.push_back(ele1);
        if(cnt2 > majorityCnt) ans.push_back(ele2);
        
        return ans;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        // return hashingSoln(nums);
        
        return MooresVotingAlgo(nums);
    }
};