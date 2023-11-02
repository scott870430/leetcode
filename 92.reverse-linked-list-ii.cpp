/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *dummy = new ListNode(-1, head), *ptr = dummy, *revptr = nullptr;
        int cnt = 1;
        while (ptr->next) // 3
        {
            if (cnt == left)
            {
                // 3                           3
                ListNode *tail = ptr->next, *reverse = ptr->next;
                while (cnt != right)
                {
                    ListNode *next = reverse->next; // 5
                    reverse->next = revptr;         // 3 -> nullptr
                    revptr = reverse;               // 3
                    reverse = next;                 // 5
                    cnt += 1;
                }
                tail->next = reverse->next; // nullptr
                // reverse->next = revptr;
                ptr->next = reverse;
                reverse->next = revptr;
                break;
            }
            ptr = ptr->next;
            cnt += 1;
        }
        return dummy->next;
    }
};
// @lc code=end
