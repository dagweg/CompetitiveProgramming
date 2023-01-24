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
    ListNode* deleteDuplicates(ListNode* head){
    ListNode* c = head;
    while (c != nullptr && c->next != nullptr) {
        if (c->val == c->next->val) {
            ListNode* d = c->next;
            c->next = c->next->next;
            delete d;
        }
        else {
            c = c->next;
        }
    }
    return head;
}
};
