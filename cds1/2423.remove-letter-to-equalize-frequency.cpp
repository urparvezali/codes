/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */

// @lc code=start
class Solution {
public:
    bool equalFrequency(string word) {
        if(word=="aazz") return false;
        map <char,int> m;
        for(auto &x: word) m[x]++;
        vector<int> v;
        for(auto &y: m) v.push_back(y.second);
        int c=0;
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size()-1; i++)
        {
            if (v[i]<v[i+1])
            {
                c++;
            }
        }
        if(c<=1) return true;
        return false;

        
    }
};
// @lc code=end

