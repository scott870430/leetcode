/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor
{
public:
    vector<vector<int>> pars;
    TreeAncestor(int n, vector<int> &parent)
    {
        pars = vector<vector<int>>(17, vector<int>(n, -1));
        for (int i = 0; i < parent.size(); i += 1)
        {
            pars[1][i] = parent[i];
        }
        for (int i = 2; i <= 16; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                pars[i][j] = pars[i - 1][pars[i - 1][j] == -1 ? 0 : pars[i - 1][j]];
            }
        }
        /*
        for (int i = 0; i <= 16; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                cout << pars[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    int getKthAncestor(int node, int k)
    {
        int num = 16;
        while (k)
        {
            if (k & (1 << num))
            {
                node = pars[num + 1][node];
                if (node == -1)
                    break;
                k ^= (1 << num);
            }
            num -= 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
