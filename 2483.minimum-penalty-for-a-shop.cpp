/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

// @lc code=start
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        vector<int> prefix(customers.size() + 1);
        int cus_sum = 0;
        for (int i = 0; i < customers.size(); i += 1)
        {
            if (customers[i] == 'Y')
            {
                cus_sum += 1;
            }
            prefix[i + 1] = cus_sum;
        }
        int close_time = 0, penalty = INT_MAX;
        int no_cus_pen = 0;
        for (int i = 0; i <= customers.size(); i += 1)
        {
            int now_pen = no_cus_pen + prefix[customers.size()] - prefix[i];
            if (penalty > now_pen)
            {
                penalty = now_pen;
                close_time = i;
            }
            if (i < customers.size() && customers[i] == 'N')
            {
                no_cus_pen += 1;
            }
        }
        return close_time;
    }
};
// @lc code=end
