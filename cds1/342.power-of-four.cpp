/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double x;
        long y;
        x= log(n)/log(4);
        y= log(n)/log(4);
        if (abs(x-y)==0)
        {
            return true;
        }
        else return false;
    }
};
// @lc code=end

