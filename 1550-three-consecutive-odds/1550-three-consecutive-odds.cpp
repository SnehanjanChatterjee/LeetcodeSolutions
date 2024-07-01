class Solution {
private:
    bool isOdd(int &x) {
        return (x % 2 == 1);
    }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cntOdds = 0;
        
        for(int i=0; i< arr.size(); i++) {
            if (isOdd(arr[i])) cntOdds++;
            else cntOdds = 0;
            
            if (cntOdds == 3) return true;
        }
        
        return false;
    }
};