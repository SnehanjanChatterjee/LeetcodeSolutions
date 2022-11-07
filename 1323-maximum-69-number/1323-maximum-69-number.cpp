class Solution {
private:
    int soln1 (int num) {
        string str = to_string(num);
        int found = str.find_first_of("6");
        if(found != string::npos) str[found] = '9';
        return stoi(str);
    }
    
    // https://leetcode.com/problems/maximum-69-number/discuss/2786958/Without-String-Conversion-oror-Written-Explanation-oror-Easy-to-understand
    int soln2 (int num) {
        int original = num, rem = 0;
        int rightDigCount = -1; //number of digits to right of last encountered '6'
        int digCount = 0; //number of digits to right of any dig at some instance
        while(num) {
            rem = num % 10;
            
            if (rem == 6) rightDigCount = digCount; //record the rightDigCount when a '6' is encountered
            digCount++;
            
            num /= 10;
        }
        
        if(rightDigCount == -1) return original;
        
        original += (3 * pow(10, rightDigCount));
        return original;
    }
public:
    int maximum69Number (int num) {
        // return soln1(num);
        
        return soln2(num);
    }
};