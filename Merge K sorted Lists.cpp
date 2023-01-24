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
        vector<int> mVec;
        for(ListNode* l : lists){
            ListNode* t = l;
            while(t != nullptr){
                mVec.push_back(t->val);
                t = t->next;
            }
        }
        if(mVec.empty()) return nullptr;
        sort(mVec.begin(), mVec.end());
        ListNode* head = new ListNode(mVec[0]);
        ListNode* cur = head;
        for(int i = 1; i < mVec.size(); i++){
            ListNode* tmp = new ListNode(mVec[i]);
            cur->next = tmp;
            cur = cur->next;
        }
        return head;   
    }
};
