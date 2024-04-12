class Solution {
private:
    double mySoln1(double x, int n) {
        double num = 1;
        long power = (n < 0) ? ((-1LL) * n) : (n);
        
        while(power>0) {
            if(power & 1L) {
                num = num*x;
                cout << "Num updated to " << num << endl;
            }
            power = power>>1;
            x = x*x;
            cout << "Now power = " << power <<", x = " << x << endl;
        }

        if(n<0) {
            num = 1/num;
        }
        return num;
    }
    
    // https://www.youtube.com/watch?v=g9YQyYi4IQQ
    double neetCodeSoln(double x, int n) {
        double res = recur(x, abs(n));
        
        return ((n >= 0) ? res : (1 / res));
    }
    double recur(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        double res = recur(x*x, n/2);
        
        return ((n % 2 == 0) ? res : (x * res));
    }
    
    // https://www.youtube.com/watch?v=l0YC3876qxg
    double striverSoln(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        
        // 2^10 = (2x2)^5 = 4^5
        // 4^5 = 4 x 4^4
        // 4^4 = (4x4)^2 = 16^2
        // 16^2 = (16x16)^1 = 256^1
        // 256^1 = 256 x 256^0
        while (nn) {
            // nn is odd
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            }
            // nn is even
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
public:
    double myPow(double x, int n) {
        // return mySoln1(x, n);
        
        // return mySoln2(x, n);
        
        // return neetCodeSoln(x, n);
        
        return striverSoln(x, n);
    }
};