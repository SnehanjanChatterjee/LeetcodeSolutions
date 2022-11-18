class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0 && i > 5) return false;
            while(n % i == 0) n /= i;
        }
        if(n > 5 || n < 0) return false;
        return true;
    }
};