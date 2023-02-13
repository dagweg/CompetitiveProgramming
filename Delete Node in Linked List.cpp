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
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* last = cur;

        while(cur->next != nullptr)
        {
            swap(cur->val, cur->next->val);
            last = cur;
            cur = cur->next;
        }
        last->next = nullptr;

    }
};
