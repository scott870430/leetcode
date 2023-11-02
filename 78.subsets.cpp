/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int p = 1 << nums.size();
        vector<vector<int>> ans(p);
        for (int i = 0; i < p; i += 1)
        {
            for (int j = 0; j < nums.size(); j += 1)
            {
                if (i & (1 << j))
                {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
