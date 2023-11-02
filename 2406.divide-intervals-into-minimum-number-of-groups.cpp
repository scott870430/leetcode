/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> dif(1e6 + 2);
        vector<int> intr(1e6 + 2);
        for (int i = 0; i < intervals.size(); i += 1)
        {
            dif[intervals[i][0]] += 1;
            dif[intervals[i][1] + 1] -= 1;
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < dif.size(); i += 1)
        {
            cnt += dif[i];
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end
