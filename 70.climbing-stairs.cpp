/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;

        int pp_step = 1, p_step = 2;
        for (int i = 3; i <= n; i += 1)
        {
            int now = pp_step + p_step;
            pp_step = p_step;
            p_step = now;
        }
        return p_step;
    }
};
// @lc code=end
