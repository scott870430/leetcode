/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i += 1)
        {
            if (ratings[i] > ratings[i - 1] && ans[i] <= ans[i - 1])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i -= 1)
        {
            if (ratings[i] > ratings[i + 1] && ans[i] <= ans[i + 1])
            {
                ans[i] = ans[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < ratings.size(); i += 1)
        {
            res += ans[i];
        }
        return res;
    }
};
// @lc code=end
