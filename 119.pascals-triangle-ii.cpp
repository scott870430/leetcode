/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
        {
            return {1, 1};
        }
        vector<int> arr1, arr2;
        arr1.push_back(1);
        arr1.push_back(1);
        rowIndex -= 1;
        while (rowIndex--)
        {
            arr2.push_back(1);
            for (int i = 0; i < arr1.size() - 1; i += 1)
            {
                arr2.push_back(arr1[i] + arr1[i + 1]);
            }
            arr2.push_back(1);
            arr1 = arr2;
            arr2.clear();
        }
        return arr1;
    }
};
// @lc code=end
