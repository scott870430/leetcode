/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        unordered_map<string, int> unmap;
        for (int i = 0; i < req_skills.size(); i += 1)
        {
            unmap[req_skills[i]] = i;
        }
        int n = people.size();
        vector<int> p(n);
        vector<int> tmp;
        for (int i = 0; i < n; i += 1)
        {
            tmp.push_back(i);
        }
        int bits = req_skills.size(), total = (1 << bits) - 1;
        vector<vector<int>> dp(total + 1, tmp);
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 0; j < people[i].size(); j += 1)
            {
                p[i] |= (1 << unmap[people[i][j]]);
            }
            dp[p[i]] = {i};
        }

        for (int i = 0; i <= total; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (dp[i | p[j]].size() > dp[i].size() + 1)
                {
                    dp[i | p[j]] = dp[i];
                    dp[i | p[j]].push_back(j);
                }
            }
        }
        return dp[total];
    }
};
// @lc code=end
