/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i += 1)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                right[st.top()] = i - 1;
                st.pop();
            }
            if (st.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
        while (!st.empty())
        {
            right[st.top()] = n - 1;
            st.pop();
        }
        long long ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i < n; i += 1)
        {
            ans = (ans + ((i - left[i] + 1) * (right[i] - i + 1) % MOD) * arr[i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end
