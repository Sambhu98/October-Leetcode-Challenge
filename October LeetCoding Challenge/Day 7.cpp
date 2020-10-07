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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || head == NULL)
            return head;

        int l = 1;
        ListNode* len = head;
        ListNode* root = head;
        while (len->next != NULL)
        {++l, len = len->next;} //calculated length

        k = k % l;
        if (!k)
            return head;

        int r = l - k;
        int r2 = r;
        while (r--)
            root = root->next;

        ListNode* ans = root;

        while (root->next != NULL)
            root = root->next;

        root->next = head;

        while (r2--)
            root = root->next;

        root->next = NULL;

        return ans;
    }
};