/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar
{
public:
    vector<array<int, 2>> cal;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (int i = 0; i < cal.size(); i += 1)
        {
            if (start < cal[i][1] && start >= cal[i][0])
            {
                return false;
            }
            if (end <= cal[i][1] && end > cal[i][0])
            {
                return false;
            }
            if (start <= cal[i][0] && end >= cal[i][1])
            {
                return false;
            }
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
