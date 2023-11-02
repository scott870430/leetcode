/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> unmap;
        // unset.insert(0);
        unmap[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 1)
        {
            sum += nums[i];
            if (unmap.find(sum % k) != unmap.end())
            {
                if (i > unmap[sum % k] + 1)
                {
                    return true;
                }
            }
            else
            {
                unmap[sum % k] = i;
            }
        }
        return false;
    }
};
// @lc code=end
