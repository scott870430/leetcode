/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    bool dfs(string now, vector<vector<string>> &tickets, vector<int> &visited)
    {
        /*
        int index = INT_MAX;
        for (int i = 0; i < tickets.size(); i += 1)
        {
            if (tickets[i][0] == now)
            {
                index = i;
                break;
            }
        }*/
        int index = lower_bound(tickets.begin(), tickets.end(), now, [](vector<string> &a, string s)
                                { return a[0] < s; }) -
                    tickets.begin();

        for (int i = index; i < tickets.size() && tickets[i][0] == now; i += 1)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                ans.push_back(tickets[i][1]);
                if (dfs(tickets[i][1], tickets, visited))
                    return true;
                ans.pop_back();
                visited[i] = 0;
            }
        }
        for (int i = 0; i < visited.size(); i += 1)
        {
            if (!visited[i])
                return false;
        }

        // ans.push_back(now);
        return true;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<int> visited(tickets.size());
        sort(tickets.begin(), tickets.end());
        ans.push_back("JFK");
        dfs("JFK", tickets, visited);
        return ans;
    }
};
// @lc code=end
