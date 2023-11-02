/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        int n = flowers.size();
        map<int, int> d, b;
        for (int i = 0; i < n; i += 1)
        {
            d[flowers[i][0]] += 1;
            d[flowers[i][1] + 1] -= 1;
        }
        int cnt = 0;
        b[0] = 0;
        for (auto p : d)
        {
            cnt += p.second;
            b[p.first] = cnt;
        }
        b[1e9 + 1] = 0;
        vector<int> ans(people.size());
        for (int i = 0; i < people.size(); i += 1)
        {
            auto p = b.upper_bound(people[i]);
            p--;
            ans[i] = p->second;
        }
        return ans;
    }
};
// @lc code=end
