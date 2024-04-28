class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0, n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (cnt == 0 && s[i] == ' ') continue;
            else if (s[i] == ' ') return cnt;
            else cnt++;
            
            cout << "cnt = " << cnt << " for s["<<i<<"] = " << s[i] << endl;
        }
        
        return cnt;
    }
};