/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, int> lsittoind;
        Node *dummy = new Node(0), *ptr = dummy, *hptr = head;
        vector<Node *> arr;
        vector<Node *> copy_arr;
        int ind = 0;
        while (hptr)
        {
            ptr->next = new Node(hptr->val);
            arr.push_back(hptr);
            copy_arr.push_back(ptr->next);
            lsittoind[hptr] = ind++;
            ptr = ptr->next;
            hptr = hptr->next;
        }
        hptr = head, ptr = dummy->next;
        while (hptr)
        {
            if (hptr->random)
                ptr->random = copy_arr[lsittoind[hptr->random]];
            ptr = ptr->next;
            hptr = hptr->next;
        }
        return dummy->next;
    }
};
// @lc code=end
