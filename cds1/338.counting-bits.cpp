/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> v;
        int c=0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if ((i&(1<<j))==1)
                {
                    c++;
                }
            }
            v.push_back(c);
            c=0;
        }
        return v;
    }
};
// @lc code=end

