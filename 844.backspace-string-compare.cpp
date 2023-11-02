/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    string op(string s)
    {
        string tmp;
        for (int i = 0; i < s.size(); i += 1)
        {
            if (s[i] != '#')
            {
                tmp += s[i];
            }
            else
            {
                if (tmp.size() > 0)
                {
                    tmp.pop_back();
                }
            }
        }
        return tmp;
    }
    bool backspaceCompare(string s, string t)
    {
        string ss = op(s), tt = op(t);
        return ss == tt;
    }
};
// @lc code=end
