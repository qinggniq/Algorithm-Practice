class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None


class Solution:
    def removeDuplicates(self, head: ListNode) -> ListNode:
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


sol = Solution()


def test_null():
    assert sol.isFlipedString('', '')


def test_single():
    assert sol.isFlipedString('a', 'a')
    assert not sol.isFlipedString('a', 'b')


def test_double():
    assert sol.isFlipedString('ab', 'ba')
    assert not sol.isFlipedString('aa', 'ab')


def test_normal():
    assert sol.isFlipedString('waterbottle', 'erbottlewat')


def test_all():
    test_null()
    test_single()
    test_double()
    test_normal()
    print("ok\n")


if __name__ == '__main__':
    test_all()
