/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> rows;
        for (int i = 0; i < mat.size(); i += 1)
        {
            int soldiers = 0;
            for (int j = 0; j < mat[i].size(); j += 1)
            {
                if (mat[i][j] == 1)
                {
                    soldiers += 1;
                }
            }
            rows.push_back({soldiers, i});
        }
        sort(rows.begin(), rows.end());
        vector<int> ans;
        for (int i = 0; i < k; i += 1)
        {
            ans.push_back(rows[i].second);
        }
        return ans;
    }
};
// @lc code=end
