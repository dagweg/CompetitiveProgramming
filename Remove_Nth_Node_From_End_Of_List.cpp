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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int len = 0;
        ListNode* temp = head;
        // determine length
        while(temp){
            len++;
            temp = temp->next;
        }
        // handle edge cases
        if(len == 1) return nullptr;
        else if(len == n)  return head->next;
        
        temp = head;
        // advance till position
        for(int i = 0 ; i < len-n-1; i++){
            temp = temp->next;
        }
        // remove the element
        if(temp->next){
            temp->next = temp->next->next;
        }

        return head;
        
    }
};
