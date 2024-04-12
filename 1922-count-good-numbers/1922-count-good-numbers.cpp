#define MOD 1000000007
typedef unsigned long long int ulli;
typedef long long int lli;

class Solution {
private:
    bool isEven(int n) {
        return (n % 2 == 0); 
    }
    
    // TLE
    // TC -> O(N)
    int frazSolution_BruteForce(long long n) {
        int possibleEvenNos = 5; // For 0-9, there are 5 possible even nos 0,2,4,6,8
        int possiblePrimeNos = 4; // For 0-9, there are 4 possible prime nos 2,3,5,7
        long long ans = 1;
        
        // At every even pos we can place nums in 5 ways i.e possibleEvenNos
        // At every odd pos we can place nums in 4 ways i.e possiblePrimeNos
        for(int i=0; i<n ; i++) {
            if(isEven(i)) ans = (ans% MOD * possibleEvenNos) % MOD;
            else ans = (ans % MOD * possiblePrimeNos) % MOD;
        }
        
        return (int)(ans % MOD);
    }
    
    // TC -> O(logN)
    int fraz_OptimalSoln(lli n) {
        int possibleEvenNos = 5; // For 0-9, there are 5 possible even nos 0,2,4,6,8
        int possiblePrimeNos = 4; // For 0-9, there are 4 possible prime nos 2,3,5,7
        lli noOfEvenIndeces = n/2 + n%2;
        lli noOfOddIndeces = n/2;
        
        return (int)((myPow(possibleEvenNos, noOfEvenIndeces) % MOD) * (myPow(possiblePrimeNos, noOfOddIndeces) % MOD) % MOD);
    }
    // https://leetcode.com/problems/powx-n/
    lli myPow(lli x, lli n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        long long res = myPow((x*x) % MOD, n/2) % MOD;
        
        return (isEven(n) ? (res % MOD) : ((x * res) % MOD));
    }
public:
    int countGoodNumbers(lli n) {
        // return fraz_BruteForceSolution(n);
        
        return fraz_OptimalSoln(n);
    }
};