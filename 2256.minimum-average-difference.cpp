/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 1)
        {
            sum += nums[i];
        }
        long long ans = INT_MAX, ind = -1;
        long long pre_sum = 0;
        for (int i = 0; i < n - 1; i += 1)
        {
            pre_sum += nums[i];
            sum -= nums[i];
            int mad = abs(pre_sum / (i + 1) - sum / (n - i - 1));
            if (ans > mad)
            {
                ans = mad;
                ind = i;
            }
        }
        pre_sum += nums.back();
        if (ans > pre_sum / n)
        {
            ind = n - 1;
        }
        return ind;
    }
};
// @lc code=end
