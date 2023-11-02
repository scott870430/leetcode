/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> unmap;
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 1)
        {
            ans += unmap[nums[i]]++;
        }
        return ans;
    }
};
// @lc code=end
