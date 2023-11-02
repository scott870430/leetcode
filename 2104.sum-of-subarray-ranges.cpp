/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */

// @lc code=start
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long bg = 0, sm = 0;
        stack<int> sts, stb;
        for (int i = 0; i < nums.size(); i += 1)
        {
            while (!sts.empty() && nums[sts.top()] > nums[i])
            {
                long long front = -1, ind = sts.top();
                sts.pop();
                if (!sts.empty())
                {
                    front = sts.top();
                }
                sm += nums[ind] * (ind - front) * (i - ind);
            }
            while (!stb.empty() && nums[stb.top()] < nums[i])
            {
                long long front = -1, ind = stb.top();
                stb.pop();
                if (!stb.empty())
                {
                    front = stb.top();
                }
                bg += nums[ind] * (ind - front) * (i - ind);
            }
            sts.push(i);
            stb.push(i);
        }
        while (!sts.empty())
        {
            long long front = -1, ind = sts.top();
            sts.pop();
            if (!sts.empty())
            {
                front = sts.top();
            }
            sm += nums[ind] * (ind - front) * (nums.size() - ind);
        }
        while (!stb.empty())
        {
            long long front = -1, ind = stb.top();
            stb.pop();
            if (!stb.empty())
            {
                front = stb.top();
            }
            bg += nums[ind] * (ind - front) * (nums.size() - ind);
        }
        return bg - sm;
    }
};
// @lc code=end
