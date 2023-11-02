/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution
{
public:
    int minDeletions(string s)
    {
        map<int, int> unmap;
        vector<int> cnt(26);

        for (int i = 0; i < s.size(); i += 1)
        {
            cnt[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i += 1)
        {
            if (cnt[i] > 0)
                unmap[cnt[i]] += 1;
        }
        int ans = 0;
        int dup = 0;
        int last = unmap.rbegin()->first;
        unmap[0] = 1;
        for (auto it = unmap.rbegin(); it != unmap.rend(); it++)
        {
            int dist = last - it->first - 1;
            if (dist > 0)
            {
                int m = min(dist, dup);
                ans += m * (m + 1) / 2;
                dup -= m;
            }
            ans += (last - it->first) * dup;
            dup += it->second - 1;
            last = it->first;
        }
        /*
        cout << last << " " << dup << endl;
        cout << ans << endl;
        last = min(last, dup);
        ans += dup * last;
        ans -= last * (last - 1) / 2;
        */
        return ans;
    }
};
// @lc code=end
