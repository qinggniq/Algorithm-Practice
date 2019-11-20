class Solution:
    def exchangeBits(self, num: int) -> int:
        return (((0xaaaaaaaa & num) >> 1) ^ ((0x55555555 & num) << 1)) & (pow(2, 31) - 1)


if __name__ == "__main__":
    print(bin(Solution().exchangeBits(0b1101)))
    print(bin(Solution().exchangeBits(0b100000000000000000001)))
