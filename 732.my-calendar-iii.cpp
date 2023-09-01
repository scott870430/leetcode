/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree
{
public:
    map<int, int> m;
    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {
        m[startTime] += 1;
        m[endTime] -= 1;
        int cnt = 0, ans = 0;
        for (auto ptr = m.begin(); ptr != m.end(); ptr++)
        {
            cnt += ptr->second;
            ans = max(cnt, ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
