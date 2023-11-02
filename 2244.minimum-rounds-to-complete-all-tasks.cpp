/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int ans = 0;
        unordered_map<int, int> unmap;
        for (int i = 0; i < tasks.size(); i += 1)
        {
            unmap[tasks[i]] += 1;
        }
        for (auto ptr : unmap)
        {
            if (ptr.second == 1)
            {
                return -1;
            }
            ans += ptr.second / 3;
            ans += ptr.second % 3 ? 1 : 0;
        }
        return ans;
    }
};
// @lc code=end
