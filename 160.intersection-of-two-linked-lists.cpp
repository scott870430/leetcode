/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA)
        {
            lenA += 1;
            ptrA = ptrA->next;
        }
        while (ptrB)
        {
            lenB += 1;
            ptrB = ptrB->next;
        }
        if (lenB > lenA)
        {
            swap(headA, headB);
            swap(lenA, lenB);
        }
        while (lenA > lenB)
        {
            lenA -= 1;
            headA = headA->next;
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
