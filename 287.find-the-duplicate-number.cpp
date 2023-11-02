/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int b = 30; b >= 0; b -= 1)
        {
            int dup = 0, org = 0;
            for (int i = 0; i < n; i += 1)
            {
                if (i != (n - 1) && (i + 1) & (1 << b))
                {
                    org += 1;
                }
                if (nums[i] & (1 << b))
                {
                    dup += 1;
                }
            }
            // cout << b << " " << dup << " " << org << endl;
            if (dup > org)
            {
                ans |= (1 << b);
            }
        }
        return ans;
    }
};
// @lc code=end
