/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution
{
public:
    long long sums(long long left, long long right, long long ind, long long num)
    {
        // cout << num * (ind - left) * (right - ind) << endl;
        return num * (ind - left) * (right - ind);
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        long long ans = 0;
        int MOD = 1e9 + 7;
        stack<int> st;
        for (int i = 0; i < arr.size(); i += 1)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                int ind = st.top();
                int num = arr[ind];
                st.pop();
                int start = -1;
                if (!st.empty())
                {
                    start = st.top();
                }
                ans = (ans + sums(start, i, ind, num)) % MOD;
            }
            st.push(i);
            // cout << ans << endl;
        }
        while (!st.empty())
        {
            int ind = st.top();
            int num = arr[ind];
            st.pop();
            int start = -1;
            if (!st.empty())
            {
                start = st.top();
            }
            ans = (ans + sums(start, arr.size(), ind, num)) % MOD;
        }
        return ans;
    }
};
// @lc code=end
