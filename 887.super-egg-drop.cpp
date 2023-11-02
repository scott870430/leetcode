/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        if (ceil(log2(n)) >= k)
        {
            return k + ceil(log2(n >> (k - 1)));
        }
        return ceil(log2(n)) + 1;
    }
};
// @lc code=end
