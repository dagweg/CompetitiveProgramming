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

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        string number = "";
        while(head != nullptr){
            number += to_string(head->val);
            head = head->next;
        }
        for(int i = 0, j = number.length()-1; i < j; i++, j--)
            if(number[i] != number[j])return false;        
        return true;    
    }
};
