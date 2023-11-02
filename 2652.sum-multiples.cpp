/*
 * @lc app=leetcode id=2652 lang=cpp
 *
 * [2652] Sum Multiples
 */

// @lc code=start
class Solution
{
public:
    int divisible(int target, int n)
    {
        int sum = 0;
        if (n >= target)
        {
            int tmp = n - (n % target);
            // cout << target << " " << tmp << endl;
            sum += (target + tmp) * ((tmp) / target) / 2;
        }
        // cout << sum << endl;
        return sum;
    }
    int sumOfMultiples(int n)
    {
        int ans = 0;

        ans += divisible(3, n);
        ans += divisible(5, n);
        ans += divisible(7, n);
        ans -= divisible(15, n);
        ans -= divisible(21, n);
        ans -= divisible(35, n);
        ans += divisible(3 * 5 * 7, n);
        return ans;
    }
};
// @lc code=end
