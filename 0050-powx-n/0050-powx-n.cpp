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
    
    // Not working
    double mySoln2(double x, int n) {
        if(n == 0) return 1;
        
        if(n < 0) {
            x = (1/(x*x));
            cout << "-ve x = " << x << endl;
            myPow(x, n+1);
        } else {
            x = x*x;
            cout << "+ve x = " << x << endl;
            myPow(x, n-1);
        }
        
        cout << "Returning x = " << x << endl;
        return x;
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
public:
    double myPow(double x, int n) {
        // return mySoln1(x, n);
        
        // return mySoln2(x, n);
        
        return neetCodeSoln(x, n);
    }
};