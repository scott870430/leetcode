/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
vector<int> dp(1e4 + 1);
int init = []
{
    dp[1] = 1;
    for (int i = 2; i <= 1e4; i += 1)
    {
        dp[i] = dp[i >> 1] + (i % 2);
    }
    return 1;
}();
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int a, int b)
             { 
                if (dp[a] == dp[b]) {
                    return a < b;
                }
                return dp[a] < dp[b]; });
        return arr;
    }
};
// @lc code=end
