/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution
{
public:
    class union_set
    {
    public:
        vector<int> root;
        vector<int> num;
        union_set(int n)
        {
            root = vector<int>(n);
            num = vector<int>(n, 1);
            for (int i = 0; i < n; i += 1)
            {
                root[i] = i;
            }
        }
        int find_root(int id)
        {
            if (root[id] == id)
                return id;
            return root[id] = find_root(root[id]);
        }
        bool same_parent(int id_a, int id_b)
        {
            int root_a = find_root(id_a), root_b = find_root(id_b);
            return root_a == root_b;
        }
        void join(int id_a, int id_b)
        {
            int root_a = find_root(id_a), root_b = find_root(id_b);
            if (num[root_a] > num[root_a])
            {
                root[root_b] = root_a;
                num[root_a] += num[root_b];
            }
            else
            {
                root[root_a] = root_b;
                num[root_b] += num[root_a];
            }
        }
    };
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            for (int j = i + 1; j < n; j += 1)
            {
                pq.push({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        int tomerge = points.size() - 1;
        union_set un(points.size());
        while (tomerge)
        {
            vector<int> edge = pq.top();
            // cout << edge[0] << endl;
            pq.pop();
            if (!un.same_parent(edge[1], edge[2]))
            {
                tomerge -= 1;
                un.join(edge[1], edge[2]);
                ans += edge[0];
            }
        }
        return ans;
    }
};
// @lc code=end
