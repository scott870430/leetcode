/*
 * @lc app=leetcode id=1879 lang=cpp
 *
 * [1879] Minimum XOR Sum of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    int bit_cnt(int n)
    {
        int cnt = 0;
        while (n)
        {
            cnt += 1;
            n = n & (n - 1);
        }
        return cnt;
    }
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int total = 1 << n;
        vector<int> dp(total, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i += 1)
        {
            for (int j = total - 1; j >= 0; j -= 1)
            {
                for (int k = 0; k < n; k += 1)
                {
                    if (j & (1 << k))
                    {
                        continue;
                    }
                    dp[j | (1 << k)] = min(dp[j | (1 << k)], dp[j] + nums1[n - k - 1] ^ nums2[i]);
                }
            }
        }
        for (int i = 0; i < total; i += 1)
        {
            cout << i << " " << dp[i] << endl;
        }
        return dp[total - 1];
    }
};
// @lc code=end
