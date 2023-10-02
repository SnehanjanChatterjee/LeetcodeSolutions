class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        int count = 0;

        prime[0] = prime[1] = false;

        for(long i=2; i<n; i++) {
            if(prime[i]) {
                count++;
                for(long j=i*i; j<=n; j+=i) {
                    prime[j] = false;
                }
            }
        }

        return count;
    }
};