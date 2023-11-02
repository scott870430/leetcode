/*
 * @lc app=leetcode id=1947 lang=cpp
 *
 * [1947] Maximum Compatibility Score Sum
 */

// @lc code=start
class Solution
{
public:
    int backtrack(vector<vector<int>> &cpt, int st_num, int vis_mot)
    {
        int max_score = 0;
        if (st_num == cpt.size())
            return 0;
        for (int i = 0; i < cpt.size(); i += 1)
        {
            if (!(vis_mot & (1 << i)))
            {
                max_score = max(max_score, cpt[st_num][i] +
                                               backtrack(cpt, st_num + 1, vis_mot | (1 << i)));
            }
        }
        return max_score;
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int m = students.size();
        vector<vector<int>> cpt(m, vector<int>(m));
        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < m; j += 1)
            {
                int cnt = 0;
                for (int k = 0; k < students[i].size(); k += 1)
                {
                    cnt += students[i][k] == mentors[j][k];
                }
                cpt[i][j] = cnt;
            }
        }
        return backtrack(cpt, 0, 0);
    }
};
// @lc code=end
