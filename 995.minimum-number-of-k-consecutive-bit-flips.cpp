/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        vector<int> dif(n + 1);
        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            cnt += dif[i];
            if (!((nums[i] + cnt) % 2))
            {
                ans += 1;
                if (i + k > n)
                {
                    return -1;
                }
                dif[i + k] -= 1;
                cnt += 1;
            }
        }
        return ans;
    }
};
// @lc code=end
