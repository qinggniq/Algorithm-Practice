class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        xor = A ^ B
        return sum((1 for i in range(31) if (xor & (1 << i) != 0)))
