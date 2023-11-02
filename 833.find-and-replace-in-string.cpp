/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

// @lc code=start
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        vector<vector<int>> pos;
        for (int i = 0; i < indices.size(); i += 1)
        {
            pos.push_back({indices[i], i});
        }
        sort(pos.begin(), pos.end());
        string ans = "";
        int ind = 0;
        for (int i = 0; i < s.size(); i += 1)
        {
            bool ismatch = false;
            while (ind < pos.size() && pos[ind][0] == i)
            {
                int oind = pos[ind][1];
                // cout << i << " " << oind << endl;
                if (s.substr(i, sources[oind].size()) == sources[oind])
                {
                    ans += targets[oind];
                    i += sources[oind].size() - 1;
                    ismatch = true;
                }
                else
                {
                }
                ind += 1;
            }
            if (!ismatch)
            {
                ans += s[i];
            }
        }
        return ans;
    }
};
// @lc code=end
