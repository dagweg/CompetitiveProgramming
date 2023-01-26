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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sorted = (ListNode*)malloc(sizeof(list1) + sizeof(list2));
        ListNode* temp = sorted;
        ListNode* tempL1 = list1;
        ListNode* tempL2 = list2;

        while(tempL1 != nullptr && list2 != nullptr){
            if(tempL1->val >= list2->val){
                temp->val = list2->val;
                list2 = list2->next;
            }else{
                temp->next = tempL1;
                temp = tempL1;
                tempL1 = tempL1->next;
            }
            temp = temp->next;   
        }
        while(list1 != nullptr){
            temp->val = list1->val;
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2 != nullptr){
            temp->val = list2->val;
            list2 = list2->next;
            temp = temp->next;
        }
        return sorted;
    }
};
