/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        vector<int> last_index(26);
        for (int i = 0; i < n; i += 1)
        {
            last_index[s[i] - 'a'] = i;
        }
        stack<char> st;
        vector<bool> seen(26, false);
        for (int i = 0; i < n; i += 1)
        {
            if (seen[s[i] - 'a'])
            {
                continue;
            }
            while (!st.empty() && st.top() > s[i] &&
                   i < last_index[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
