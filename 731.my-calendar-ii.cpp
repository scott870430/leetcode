/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo
{
public:
    map<int, int> m;
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        int cnt = 0;
        m[start] += 1;
        m[end] -= 1;
        for (auto p = m.begin(); p != m.end(); p++)
        {
            cnt += p->second;
            if (cnt > 2)
            {
                m[start] -= 1;
                if (m[start] == 0)
                    m.erase(start);
                m[end] += 1;
                if (m[end] == 0)
                    m.erase(end);
                return false;
            }
            // cout << p->first << " " << cnt << endl;
        }

        // m[end] += 1;
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
