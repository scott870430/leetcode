/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void rec(vector<int> &nums, int visited, vector<int> &arr)
    {
        if (visited == ((1 << nums.size()) - 1))
        {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i += 1)
        {
            if (!(visited & (1 << i)))
            {
                arr.push_back(nums[i]);
                rec(nums, visited | (1 << i), arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int visited = 0;
        vector<int> arr;
        rec(nums, visited, arr);
        return ans;
    }
};
// @lc code=end
