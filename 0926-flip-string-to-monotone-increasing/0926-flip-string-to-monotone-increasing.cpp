class Solution {
public:
    // https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/3061178/C%2B%2BEasy-solution-with-explainationWithout-Dp
    int minFlipsMonoIncr(string s) {
        int count_flip = 0, count_one = 0;
        for (auto itr : s) { 
            //keep track of all one (we will use count_one in else condition if we need)  
            //if we want flip one into 0
            if (itr == '1') {
                count_one++;
            } else {
                count_flip++;
                count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};