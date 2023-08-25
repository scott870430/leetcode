/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
public:
    int DP[205][205];
    class strings
    {
    public:
        string s1, s2, s3;
        strings(string _s1, string _s2, string _s3) : s1(_s1), s2(_s2), s3(_s3) {}
    };
    bool rec(strings &s, int i1, int i2, int i3)
    {
        if (i3 == s.s3.size() && i1 == s.s1.size() && i2 == s.s2.size())
        {
            return true;
        }
        if (i1 == s.s1.size() && i2 == s.s2.size())
            return false;

        if (DP[i1][i2] != -1)
            return DP[i1][i2];

        DP[i1][i2] = 0;
        if (i1 < s.s1.size() && s.s1[i1] == s.s3[i3])
        {
            DP[i1][i2] |= rec(s, i1 + 1, i2, i3 + 1);
        }
        if (i2 < s.s2.size() && s.s2[i2] == s.s3[i3])
        {
            DP[i1][i2] |= rec(s, i1, i2 + 1, i3 + 1);
        }
        // cout << i1 << " " << i2 << " " << i3 << " " << DP[i1][i2][i3] << endl;
        return DP[i1][i2];
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size();
        memset(DP, -1, sizeof(DP));
        strings s(s1, s2, s3);
        return rec(s, 0, 0, 0);
    }
};
// @lc code=end
