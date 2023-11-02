/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;

        unordered_map<int, vector<int>> unmap;
        for (int i = 0; i < groupSizes.size(); i += 1)
        {
            unmap[groupSizes[i]].push_back(i);
        }
        for (auto it = unmap.begin(); it != unmap.end(); it++)
        {
            vector<int> group;
            for (int j = 0; j < it->second.size(); j += 1)
            {
                group.push_back(it->second[j]);
                if ((j + 1) % it->first == 0)
                {
                    ans.push_back(group);
                    group.clear();
                }
            }
        }
        return ans;
    }
};
// @lc code=end
