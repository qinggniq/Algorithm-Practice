import random
import json
AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 13
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 20000


class Solution:
    def removeDup(self, data: list) -> list:
        from collections import Counter
        seen = set()
        res = []
        for d in data:
            if d not in seen:
                res.append(d)
                seen.add(d)
        return res


class RemoveDuplicateNodesCaseGenerator:

    def __init__(self, file_out, case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')

    def output_str(self, s):
        self.fout.write('\"%s\"\n' % s)

    def output_array(self, arr):
        self.fout.write(str(arr))
        self.fout.write('\n')

    def gen_a_random_array(self, length, rate=0.5):
        ret = []
        i = 0
        uppper = int(length * rate)
        while i < length:
            ret.append(random.randint(0, uppper))
            i += 1
        self.output_array(ret)

    def gen_series_array(self, nsamp, large_L):
        for _ in range(int(nsamp)):
            l = random.randint(1, large_L)
            self.gen_a_random_array(l)

    def gen_special_case(self):
        print(type(''))
        self.output_array([1, 2, 3, 3, 2, 1])
        self.output_array([1, 1, 1, 1, 2])
        self.output_array([])
        self.output_array([1])
        self.output_array([1, 1, 2, 1, 1])

    def gen_small_cases(self):
        self.gen_series_array(N_SMALL_SAMPLE, L_SMALL)

    def gen_large_cases(self):
        self.gen_series_array(N_LARGE_SAMPLE, L_LARGE)

    def gen_boundary_string(self):
        self.gen_a_random_array(L_BOUDERY)
        self.gen_a_random_array(L_BOUDERY)

    def gen_all_cases(self):
        self.gen_special_case()
        self.gen_small_cases()
        self.gen_large_cases()
        self.gen_boundary_string()
        self.fout.close()


solution = Solution()


def get_res(file_out, file_in):
    lines = []
    with open(file_in, "r") as fin:
        lines = fin.readlines()
    with open(file_out, "w") as fout:
        for line in lines:
            arr = json.loads(line)
            fout.write(str(solution.removeDup(arr)))
            fout.write('\n')


if __name__ == '__main__':
    tg = RemoveDuplicateNodesCaseGenerator('input_file')
    tg.gen_all_cases()
    get_res('output_file', 'input_file')
