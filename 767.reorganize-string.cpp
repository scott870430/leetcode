/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> unmap;
        char maxChar;

        int maxNum = 0;
        for (int i = 0; i < s.size(); i += 1)
        {
            unmap[s[i]] += 1;
            if (unmap[s[i]] > (s.size() + 1) / 2)
            {
                return "";
            }
            if (unmap[s[i]] > maxNum)
            {
                maxNum = unmap[s[i]];
                maxChar = s[i];
            }
        }
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for (auto i : unmap)
        {
            pq.push({i.second, i.first});
        }
        while (!pq.empty())
        {
            auto chara = pq.top();
            pq.pop();
            ans += chara.second;
            if (!pq.empty())
            {
                auto charb = pq.top();
                pq.pop();
                ans += charb.second;
                if (charb.first != 1)
                {
                    pq.push({charb.first - 1, charb.second});
                }
            }
            if (chara.first != 1)
            {
                pq.push({chara.first - 1, chara.second});
            }
        }
        return ans;
    }
};
// @lc code=end
