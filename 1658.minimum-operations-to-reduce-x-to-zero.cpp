/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int ans = INT_MAX;
        int step = 0;
        int ptr = nums.size() - 1;
        for (int i = 0; i < nums.size(); i += 1)
        {
            x -= nums[i];
            step += 1;
            if (x < 0)
            {
                ptr = i - 1;
                step -= 1;
                x += nums[i];
                break;
            }
        }
        if (x == 0)
        {
            ans = min(ans, step);
        }
        for (int i = nums.size() - 1; i >= 0 && i > ptr; i -= 1)
        {
            x -= nums[i];
            step += 1;
            while (ptr >= 0 && x < 0)
            {
                x += nums[ptr--];
                step -= 1;
            }
            if (x == 0)
            {
                ans = min(ans, step);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
