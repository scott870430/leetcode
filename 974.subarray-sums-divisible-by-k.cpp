/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int sum = 0, ans = 0;
        unordered_map<int, int> remainder_cnt;
        remainder_cnt[0] = 1;
        for (int i = 0; i < nums.size(); i += 1)
        {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            ans += remainder_cnt[rem];
            remainder_cnt[rem] += 1;
        }
        return ans;
    }
};
// @lc code=end
