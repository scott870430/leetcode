/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> unmap;
        int sum = 0, ans = 0;
        unmap[0] = -1;
        for (int i = 0; i < nums.size(); i += 1)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (unmap.find(sum) == unmap.end())
            {
                unmap[sum] = i;
            }
            else
                　
                {
                    ans = max(ans, i - unmap[sum]);
                }
        }
        return ans;
    }
};
// @lc code=end
