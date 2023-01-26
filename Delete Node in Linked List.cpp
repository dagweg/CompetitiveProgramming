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
        ListNode* c = node;
        ListNode* t = node;

        int temp;
        while(t->next != nullptr){
            temp = t->val;
            t->val = t->next->val;
            t->next->val = temp;
            c = t;
            t = t->next;
        }
        c->next = nullptr;
    }
};
