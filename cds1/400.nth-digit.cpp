/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        string s;
        for (long i = 1; i < 1e5; i++)
        {
            s+=to_string(i);
        }
        n=(s[n-1]-'0');
        return n;
    }
};
// @lc code=end

