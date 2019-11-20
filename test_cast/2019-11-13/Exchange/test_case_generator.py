import random
import json
from cyaron import Graph


AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
AVAILABLE_CHARS.append(' ')
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 500000


class Solution:
    def exchangeBits(self, num: int) -> int:
        return (((0xaaaaaaaa & num) >> 1) ^ ((0x55555555 & num) << 1)) & (pow(2, 31) - 1)


class StringTestGenerator:
    def __init__(self, out_fun):
        self.output = out_fun

    def gen_a_random_string(self, length):
        ret = []
        i = 0
        while i < length:
            times = min(random.randint(0, int(length/10+1)), length - i)
            i += times
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)]*times)
        self.output(''.join(ret))

    # generate a string that not suitable to compress
    def gen_a_unsutiable_string(self, length):
        ret = []
        i = 0
        while i < length:
            times = min(max(1, random.randint(0, 3)), length - i)
            i += times
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)]*times)
        self.output(''.join(ret))

    # def gen_correct_string(self, length):
    #     ret = []
    #     for _ in range(length):
    #         ret.append(AVAILABLE_CHARS[random.randint(
    #             0, len(AVAILABLE_CHARS) - 1)])
    #     rn = random.randint(0, len(ret) - 1)
    #     ret2 = ret[rn:] + ret[:rn]
    #     self.output(''.join(ret), ''.join(ret2))

    def gen_series_string(self, nsamp, large_L):
        for _ in range(int(nsamp/2)):
            l = random.randint(1, large_L)
            self.gen_a_random_string(l)
            self.gen_a_unsutiable_string(l)


class ClosedNumberTestcaseGenerator():
    def __init__(self, output):
        self.output = output

    def gen_bad_cases(self, length):
        num = random.randint(0,  pow(2, 30) - 1)
        self.output(num)

    def gen_random_cases(self, length):
        num = random.randint(0, pow(2, 30) - 1)
        self.output(num)

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class TestCaseGenerator:

    def __init__(self, file_out='input_file', case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')
        self.listGen = ClosedNumberTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(3)
        self.output(1)

    def gen_small_cases(self):
        # self.gen_series_string(N_SMALL_SAMPLE, L_SMALL)
        self.listGen.gen_series_cases(N_SMALL_SAMPLE, L_SMALL)
        pass

    def gen_large_cases(self):
        # self.gen_series_string(N_LARGE_SAMPLE, L_LARGE)
        self.listGen.gen_series_cases(N_LARGE_SAMPLE, L_LARGE)
        pass

    def gen_boundary_case(self):
        # self.gen_a_random_string(L_BOUDERY)
        # self.gen_a_unsutiable_compress_string(L_BOUDERY)
        self.listGen.gen_random_cases(L_BOUDERY)
        self.listGen.gen_bad_cases(L_BOUDERY)
        pass

    def gen_all_cases(self):
        self.gen_special_case()
        self.gen_small_cases()
        self.gen_large_cases()
        self.gen_boundary_case()
        self.fout.close()


def get_res(file_in, file_out):
    lines = []
    sol = Solution()
    with open(file_in, "r") as fin:
        lines = fin.readlines()
        print(lines[:4])
    with open(file_out, "w") as fout:
        for i in range(0, len(lines), 1):
            num = int(lines[i])
            json.dump(sol.exchangeBits(num), fout)
            fout.write('\n')


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
