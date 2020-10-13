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
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        vector<int> nodes;
        ListNode *root = head;
        ListNode *r = root;
        while (head != NULL)
        {
            nodes.push_back(head->val);
            head = head->next;
        }
        sort(nodes.begin(), nodes.end());
        int i = 0;
        while (i < nodes.size())
        {
            root->val = nodes[i];
            root = root->next;
            i++;
        }
        return r;
    }
};