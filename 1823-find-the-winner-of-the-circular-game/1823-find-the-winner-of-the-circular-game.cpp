class Solution {
private:
    int recur(vector<int> &friends, int &k, int &ind) {
        int n = friends.size();
        
        if(n == 0) return -1;
        if(n == 1) return friends[0];
        
        ind = (ind + k) % n;
        
        friends.erase(friends.begin() + ind);
        
        return recur(friends, k, ind);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);
        int ind = 0;
        
        for (int i = 0; i < n; i++) friends[i] = i + 1;
        
        k--;
        int ans = recur(friends, k, ind);
        
        return ans;
        
    }
};