/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int left = 0, right = 0;
        int cnt = 0, ans = k;
        while (right < blocks.size())
        {
            cnt += blocks[right] == 'B';
            if (right - left + 1 > k)
            {
                cnt -= blocks[left++] == 'B';
            }
            if (right - left + 1 == k)
                ans = min(ans, k - cnt);
            right += 1;
        }
        return ans;
    }
};
// @lc code=end
