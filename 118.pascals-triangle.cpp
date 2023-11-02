/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }
        vector<vector<int>> ans{{1}, {1, 1}};
        vector<int> pre = ans.back();
        for (int i = 3; i <= numRows; i += 1)
        {
            vector<int> now{1};
            for (int j = 0; j < pre.size() - 1; j += 1)
            {
                // cout << j << " " << pre.size() << endl;
                now.push_back(pre[j] + pre[j + 1]);
            }
            now.push_back(1);
            ans.push_back(now);
            pre = now;
        }
        return ans;
    }
};
// @lc code=end
