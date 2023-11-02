/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> ans;
    void rec(TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (ans.size() == depth)
        {
            ans.push_back(root->val);
        }
        ans[depth] = max(ans[depth], root->val);
        rec(root->left, depth + 1);
        rec(root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        rec(root, 0);
        return ans;
    }
};
// @lc code=end
