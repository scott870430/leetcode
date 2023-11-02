/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int A = 0, B = 0, cnt = 0;
        for (int i = 1; i < colors.size(); i += 1)
        {
            if (colors[i] == colors[i - 1])
            {
                cnt += 1;
            }
            else
            {
                if (colors[i] == 'A')
                {
                    B += max(0, cnt - 1);
                }
                else
                {
                    A += max(0, cnt - 1);
                }
                cnt = 0;
            }
        }
        if (cnt > 0)
        {
            if (colors[colors.size() - 1] == 'A')
            {
                A += cnt - 1;
            }
            else
            {
                B += cnt - 1;
            }
        }
        return A > B;
    }
};
// @lc code=end
