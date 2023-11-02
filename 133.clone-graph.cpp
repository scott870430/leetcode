/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    vector<Node *> nodes;
    void dfs(Node *node)
    {
        if (!node)
            return;
        int ind = node->val;
        if (nodes[ind] == nullptr)
        {
            nodes[ind] = new Node(ind);
        }
        else
        {
            return;
        }
        for (int i = 0; i < node->neighbors.size(); i += 1)
        {
            dfs(node->neighbors[i]);
            nodes[ind]->neighbors.push_back(nodes[node->neighbors[i]->val]);
        }
    }
    Node *cloneGraph(Node *node)
    {
        nodes = vector<Node *>(101);
        dfs(node);
        return nodes[1];
    }
};
// @lc code=end
