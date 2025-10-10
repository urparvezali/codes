/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int a=-1,b=-1;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]!=goal[i]){
            if(a==-1)
            a=i;
            else b=i;
            }
                
        }
        if(s==goal) return false;
        char temp = s[a];
        s[a]=s[b];
        s[b]=temp;
        if(s==goal) return true;
        return false;
    }
};
// @lc code=end

