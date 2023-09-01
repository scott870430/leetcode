/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
            return {0};
        vector<int> DP(n + 1, 0);
        DP[1] = 1;
        for (int i = 2; i <= n; i += 1)
        {
            if (i & 1)
            {
                DP[i] = DP[i - 1] + 1;
            }
            else
            {
                DP[i] = DP[i >> 1];
            }
        }
        return DP;
    }
};
// @lc code=end
