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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        int length = 0 ;
        ListNode* cursor = head;
        while(cursor != nullptr){
            length++;
            cursor = cursor->next;
        }
        int middle = length / 2;
        length = 0;
        cursor = head;
        while (cursor != nullptr)
        {
            if(length == middle){
                head = cursor;
                return head;
            }
            length++;
            cursor = cursor->next;
        }
        return head;
        
    }
};
