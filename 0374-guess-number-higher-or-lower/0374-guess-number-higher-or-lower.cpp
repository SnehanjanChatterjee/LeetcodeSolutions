/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int binarySearch(int l, int h) {
        if(l <= h) {
            int mid = l + (h - l) / 2;
            int pick = guess(mid);
            if(pick == -1) return binarySearch(l, mid - 1);
            else if(pick == 1) return binarySearch(mid + 1, h);
            if(pick == 0) return mid;
        }
        return -1;
    }
public:
    int guessNumber(int n) {
        return binarySearch(1, n);
    }
};