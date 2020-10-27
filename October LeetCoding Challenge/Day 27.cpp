/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> mp;
        while (head != NULL)
        {
            if (mp.find(head) != mp.end())
                return head;

            mp[head] = true;
            head = head->next;
        }
        return head;
    }
};