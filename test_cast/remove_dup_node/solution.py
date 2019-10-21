# class ListNode:
#     def __init__(self, val=0):
#         self.val = val
#         self.next = None


class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        seen = set()
        tmp = ListNode()
        tail = tmp
        while head.next != None:
            if head.val not in seen:
                tail.next = head
                tail = tail.next
                seen.add(head.val)
            head = head.next
        return tmp.next
