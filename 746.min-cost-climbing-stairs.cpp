/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int pre = 0, pp = 0;
        for (int i = 2; i < cost.size(); i += 1)
        {
            int now = min(pre + cost[i - 1], pp + cost[i - 2]);
            pp = pre;
            pre = now;
        }
        return min(pre + cost.back(), pp + cost[cost.size() - 2]);
    }
};
// @lc code=end
