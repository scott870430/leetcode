/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size(), ans = 0, sum = 0;
        for (int i = 0; i < n; i += 1)
        {
            sum += arr[i];
            if (i - k >= 0)
            {
                sum -= arr[i - k];
            }
            if (i >= k - 1)
            {
                if ((double)sum / k >= threshold)
                {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

// @lc code=end
