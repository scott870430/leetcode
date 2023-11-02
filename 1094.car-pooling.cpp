/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> dif(1005);
        for (int i = 0; i < trips.size(); i += 1)
        {
            dif[trips[i][1]] += trips[i][0];
            dif[trips[i][2]] -= trips[i][0];
        }
        int pass = 0;
        for (int i = 0; i <= 1000; i += 1)
        {
            pass += dif[i];
            if (pass > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
