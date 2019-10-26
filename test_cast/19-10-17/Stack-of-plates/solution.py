class Solution:
    def __init__(self, cap):
        self.cap = cap
        self.stacks = []
    def push(self, val : int):
        if len(self.stacks) == 0 or len(self.stacks[-1]) == cap:
            self.stacks.append([])
            self.stacks[-1].append(val)
        else:
            self.stacks[-1].append(val)
    
    def pop(self, val : int) -> int:
        if len(self.stacks) == 0:
            return -1
        res = self.stacks[-1][-1]
        if len(self.stacks[-1]) == 1:
            self.stacks.pop()
        else:
            self.stacks[-1].pop()
        return res
    def popAt(self, index : int) -> int:
        if len(self.stacks) < index or len(self.stacks[index]) == 0:
            return -1
        return self.stacks[index].pop()
