# class ListNode:
#     def __init__(self, val=0):
#         self.val = val
#         self.next = None


class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        from collections import Counter
        cur = head
        save = []
        while cur.next != None:
            save.append(cur.val)
        cnts = Counter(save)
        tmp = ListNode()
        tail = tmp
        cur = head
        while head.next != None:
            if cnts[head.val] == 1:
                tail.next = head
                tail = tail.next
            else:
                cnts[head.val] -= 1
            head = head.next
        return tmp.next
