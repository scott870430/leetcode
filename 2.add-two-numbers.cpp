/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addlist(ListNode *l1, ListNode *l2, int addone)
    {
        if (!l1 && !l2 && !addone)
            return nullptr;
        ListNode *node = new ListNode();
        node->val += addone;
        if (l1)
        {
            node->val += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            node->val += l2->val;
            l2 = l2->next;
        }
        addone = node->val / 10;
        node->val %= 10;
        node->next = addlist(l1, l2, addone);
        return node;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addlist(l1, l2, 0);
    }
};
// @lc code=end
