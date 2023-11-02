/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    int ind = 0;
    vector<int> ans;
    void process(NestedInteger n)
    {
        if (n.isInteger())
        {
            ans.push_back(n.getInteger());
        }
        else
        {
            processl(n.getList());
        }
    }
    void processl(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i += 1)
        {
            process(nestedList[i]);
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i += 1)
        {
            process(nestedList[i]);
        }
    }

    int next()
    {
        return ans[ind++];
    }

    bool hasNext()
    {
        return !(ind == ans.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
