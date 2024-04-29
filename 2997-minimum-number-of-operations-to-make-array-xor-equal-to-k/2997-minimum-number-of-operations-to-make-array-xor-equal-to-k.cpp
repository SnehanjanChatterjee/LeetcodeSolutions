class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int allXor = 0;
        
        for (int &x: nums) allXor ^= x;
        
        // Do xor of (xor of all nos) and k
        allXor ^= k;
        
        int count = 0;
        
        // Brian Kerninghan's Algorithm -> Count no of set bits.
        while (allXor > 0) {
            allXor = allXor & (allXor - 1);
            count++;
        }

        // For each set bit -> There were that many different bits b/w allXor and k.
        // For each different bit between the bitwise XOR of elements of the original array and k,
        // we have to flip exactly one bit of an element in nums to make that bit equal.
        return count;
    }
};