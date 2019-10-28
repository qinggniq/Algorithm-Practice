
# https://my.oschina.net/u/2822116/blog/789374


class Stack:
        def __init__(self):
            self.val = 0
            self.prevIndex = -1


class Solution:

    def __init__(self, cap):
        self.stack = []
        self.cap = cap
        self.array = [Stack()] * cap
        self.topPoints = [-1, -1, -1]
        self.cnt = 0

    def push(self, val: int, stackNum: int):
        if self.cap == self.cnt:
            return
        lastIndex = self.topPoints[stackNum]
        self.topPoints[stackNum] = self.cnt

        self.array[self.topPoints[stackNum]].val = val
        self.array[self.topPoints[stackNum]].prevIndex = lastIndex

        self.cnt += 1

    def pop(self, stackNum: int):
        if self.topPoints[stackNum] == -1:
            return
        self.topPoints[stackNum] = self.array[self.topPoints[stackNum]].prevIndex

    def peek(self, stackNum: int) -> int:
        if self.topPoints[stackNum] == -1:
            return -1

        return self.array[self.topPoints[stackNum]].val

    def isEmpty(self, stackNum: int) -> bool:
        return self.topPoints[stackNum] == -1
