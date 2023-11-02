/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *ptr = head;
        int cnt = 0;
        while (ptr)
        {
            cnt += 1;
            ptr = ptr->next;
        }
        vector<ListNode *> ans(k);
        int avg = cnt / k, remainder = cnt % k, ind = 0;
        ptr = head;
        cnt = 0;
        while (ptr)
        {
            if (cnt == 0)
            {
                ans[ind++] = ptr;
            }
            cnt += 1;
            ListNode *next = ptr->next;
            if (cnt == avg + (remainder > 0))
            {
                cnt = 0;
                ptr->next = nullptr;
                remainder -= 1;
            }
            ptr = next;
        }
        return ans;
    }
};
// @lc code=end
