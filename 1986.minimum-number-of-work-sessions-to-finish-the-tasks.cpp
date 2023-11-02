/*
 * @lc app=leetcode id=1986 lang=cpp
 *
 * [1986] Minimum Number of Work Sessions to Finish the Tasks
 */

// @lc code=start
class Solution
{
public:
    int rec(vector<int> &tasks, int ses, int mask, int get, vector<vector<int>> &dp)
    {
        int all = (1 << tasks.size()) - 1;
        if (dp[get][mask] != 20)
        {
            return dp[get][mask];
        }
        if (mask == all)
        {
            return 0;
        }
        /*
        if (dp[mask] != 20)
        {
            return dp[mask];
        }*/
        int nn = mask ^ all;
        int now = (1 << tasks.size() - 1);
        for (int i = tasks.size() - 1; i >= 0; i -= 1)
        {
            if ((1 << i) & nn)
            {
                int t = tasks.size() - i - 1;

                int h = 0, add = 0;
                if (get == 0)
                {
                    add = 1;
                }
                if (tasks[t] == ses)
                {
                    if (get != 0)
                    {
                        add += 1;
                    }
                }
                else if (get + tasks[t] > ses)
                {
                    h = tasks[t];
                    add += 1;
                }
                else if (get + tasks[t] == ses)
                {
                    h = 0;
                }
                else
                {
                    h = get + tasks[t];
                }
                dp[get][mask] = min(dp[get][mask], add + rec(tasks, ses, mask | (1 << i), h, dp));
            }
        }
        return dp[get][mask];
    }
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        int total = 1 << n;
        vector<vector<int>> dp(sessionTime, vector<int>(total, 20));
        return rec(tasks, sessionTime, 0, 0, dp);
        // return dp[0];
    }
};
// @lc code=end
//[5,7,8,6]\n12