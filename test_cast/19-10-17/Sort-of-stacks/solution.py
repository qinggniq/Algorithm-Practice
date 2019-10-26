import random


class Solution:
    def __init__(self):
        self.st1 = []
        self.st2 = []

    def push(self, val: int):
        while len(self.st1) > 0 and val > self.st1[-1]:
            self.st2.append(self.st1[-1])
            self.st1.pop()
        self.st1.append(val)
        while len(self.st2) > 0:
            self.st1.append(self.st2[-1])
            self.st2.pop()

    def pop(self):
        if not self.isEmpty():
            self.st1.pop()

    def peek(self):
        if not self.isEmpty():
            return self.st1[-1]
        return -1

    def isEmpty(self):
        return len(self.st1) == 0


def test_push():
    sol = Solution()
    sol.push(1)
    sol.push(2)
    sol.push(3)
    while not sol.isEmpty():
        print(sol.peek())
        sol.pop()


def test_normal():
    sol = Solution()
    for _ in range(20):
        sol.push(random.randint(0, 40))
    res = []
    while not sol.isEmpty():
        res.append(sol.peek())
        sol.pop()
    print(res)


# if __name__ == "__main__":
#     test_normal()
#     test_push()
