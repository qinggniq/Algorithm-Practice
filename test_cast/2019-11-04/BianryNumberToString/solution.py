import random


class Solution:
    def printBin(self, num: int) -> str:
        if num >= 1 or num < 0:
            return "ERROR"
        binary = '0.'
        frac = 0.5
        while num > 0:
            # print(binary)
            if len(binary) > 32:
                return "ERROR"
            if num >= frac:
                num -= frac
                binary += '1'
            else:
                binary += '0'
            frac /= 2
        return binary


def gen_good_num():
    ret = []
    for i in range(2, pow(2, 30)):
        ret.append(1/i)
    return ret


if __name__ == '__main__':
    print(Solution().printBin(1 / random.randint(2, pow(2, 20))))
