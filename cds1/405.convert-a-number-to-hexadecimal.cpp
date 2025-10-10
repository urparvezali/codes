/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num)
    {
        string hex = "";
        char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while (num > 0)
        {
            int remainder = num % 16;
            hex = hexChars[remainder] + hex;
            num = num / 16;
        }
        return hex;
    }
};
// @lc code=end

