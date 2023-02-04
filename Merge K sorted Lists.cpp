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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // naive solution O(n^2)
        if(lists.empty()) return nullptr;
        ListNode* head = new ListNode();
        ListNode* cursor = head;
        // concatenate
        for(ListNode*& list : lists){
            while(list != nullptr){
                ListNode* temp = new ListNode(list->val);
                cursor->next = temp;
                cursor = temp;
                list = list->next;
            }
        }
        head = head->next;
        // sort
        for(ListNode* prev = head; prev != nullptr; prev=prev->next){
            for(ListNode* curr = prev->next; curr != nullptr; curr=curr->next){
                if(prev->val>curr->val){
                    int tmp= prev->val;
                    prev->val= curr->val;
                    curr->val= tmp;
                }
            }
        }
        return head;    
    }
};
