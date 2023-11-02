/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<int, int> unmap;

        for (int i = 0; i < s.size(); i += 1)
        {
            unmap[s[i]] += 1;
        }
        for (int j = 0; j < t.size(); j += 1)
        {
            unmap[t[j]] -= 1;
            if (unmap[t[j]] < 0)
            {
                return t[j];
            }
        }
        return '\0';
    }
};
// @lc code=end
