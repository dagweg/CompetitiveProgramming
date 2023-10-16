# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return head

        dummy, slow , fast = None , head, head.next

        while fast:
            if slow.val == fast.val:
                while fast and slow.val == fast.val:
                    fast = fast.next
                
                if dummy == None:
                    head = fast
                    slow = head
                else:
                    dummy.next = fast
                    slow = fast
                    
                fast = fast.next if fast else fast
            else:
                dummy = slow
                slow = slow.next
                fast = fast.next    
            
        return head
         

