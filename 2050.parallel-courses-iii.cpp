/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> pre(n + 1);
        vector<int> cmptime(n + 1), degree(n + 1);
        for (int i = 0; i < relations.size(); i += 1)
        {
            pre[relations[i][0]].push_back(relations[i][1]);
            degree[relations[i][1]] += 1;
        }
        queue<int> q;
        for (int i = 1; i <= n; i += 1)
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            int cls = q.front();
            q.pop();
            int cst_tm = cmptime[cls] + time[cls - 1];
            // cout << cls << " " << cst_tm << endl;
            ans = max(cst_tm, ans);
            for (int i = 0; i < pre[cls].size(); i += 1)
            {
                int next = pre[cls][i];
                degree[next] -= 1;
                if (degree[next] == 0)
                {
                    q.push(next);
                }
                cmptime[next] = max(cmptime[next], cst_tm);
            }
        }
        return ans;
    }
};
// @lc code=end
