/*
 * @lc app=leetcode id=2654 lang=cpp
 *
 * [2654] Minimum Number of Operations to Make All Array Elements Equal to 1
 */

// @lc code=start
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    int minOperations(vector<int> &nums)
    {
        int dist = nums.size();
        int cnt_one = 0;
        for (int i = 0; i < nums.size(); i += 1)
        {
            int tmp = nums[i];
            if (tmp == 1)
            {
                cnt_one += 1;
            }
            for (int j = i + 1; j < nums.size(); j += 1)
            {
                tmp = gcd(tmp, nums[j]);
                if (tmp == 1)
                {
                    dist = min(dist, j - i);
                }
            }
        }
        if (dist == nums.size())
        {
            return -1;
        }
        return nums.size() - 1 + dist - cnt_one;
    }
};
// @lc code=end
