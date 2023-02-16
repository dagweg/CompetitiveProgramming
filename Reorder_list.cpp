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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> half;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        while(cur){
            half.push(cur);
            cur = cur->next;
        }

        ListNode* trav = head;
        while(!half.empty()){
            ListNode* tmp = trav->next;
            trav->next = half.top();
            trav = tmp;
            half.top()->next = trav;
            half.pop();
        }

    }
};
