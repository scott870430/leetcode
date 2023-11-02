/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i += 1)
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size())
            {
                if (s[l] != s[r])
                {
                    break;
                }
                l -= 1;
                r += 1;
            }
            if (ans.size() < r - l - 1)
            {
                ans = s.substr(l + 1, r - l - 1);
            }
            if (i < s.size() - 1)
            {
                l = i;
                r = i + 1;
                while (l >= 0 && r < s.size())
                {
                    if (s[l] != s[r])
                    {
                        break;
                    }
                    l -= 1;
                    r += 1;
                }
                if (ans.size() < r - l - 1)
                {
                    ans = s.substr(l + 1, r - l - 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
