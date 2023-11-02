/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefix_cnt;
        int cnt = 0, ans = 0;
        prefix_cnt[0] += 1;
        for (int i = 0; i < nums.size(); i += 1)
        {
            cnt += nums[i];
            ans += prefix_cnt[cnt - k];
            prefix_cnt[cnt] += 1;
        }
        return ans;
    }
};
// @lc code=end
