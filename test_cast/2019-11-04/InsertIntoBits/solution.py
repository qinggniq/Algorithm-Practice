class Solution:
    def insertBits(self, N: int, M: int, i: int, j: int) -> int:
        for k in range(i, j + 1):
            N ^= (((1 << (k - i)) & N) << i)
            N |= (((1 << (k - i)) & M) << i)
        return N
