/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_ptr = 0, t_ptr = 0;
        while (s_ptr < s.size() && t_ptr < t.size())
        {
            if (s[s_ptr] == t[t_ptr])
            {
                s_ptr += 1;
            }
            t_ptr += 1;
        }
        return s_ptr == s.size();
    }
};
// @lc code=end
