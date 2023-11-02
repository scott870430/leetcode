/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 2;
        }
        int ans = 1;
        while (n)
        {
            if (n == 4)
            {
                ans *= 4;
                n -= 4;
            }
            else if (n == 2)
            {
                ans *= 2;
                n -= 2;
            }
            else
            {
                n -= 3;
                ans *= 3;
            }
        }
        return ans;
    }
};
// @lc code=end
