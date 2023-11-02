/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> unmap;
        for (int i = 0; i < words.size(); i += 1)
        {
            unmap[words[i]] = 1;
        }
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.size() < b.size(); });

        int ans = 0;

        for (int i = 0; i < words.size(); i += 1)
        {
            for (int j = 0; j < words[i].size(); j += 1)
            {
                string tmp = words[i].substr(0, j) + words[i].substr(j + 1);
                unmap[words[i]] = max(unmap[words[i]], unmap[tmp] + 1);
                ans = max(unmap[words[i]], ans);
            }
        }
        return ans;
    }
};
// @lc code=end
