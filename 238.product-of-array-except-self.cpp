/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre(nums.size(), 1), suf(nums.size(), 1);
        int pprod = 1, sprod = 1;
        for (int i = 1; i < nums.size(); i += 1)
        {
            pprod *= nums[i - 1];
            sprod *= nums[nums.size() - i];
            pre[i] = pprod;
            suf[nums.size() - i - 1] = sprod;
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i += 1)
        {
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }
};
// @lc code=end
