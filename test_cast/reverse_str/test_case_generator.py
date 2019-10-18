import random

AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 5000
L_BOUDERY = 50000


class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        return s1 in s2 + s2


class FilppedStringTestCaseGenerator:

    def __init__(self, file_out, case_num=20):

        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')

    def output_str(self, s1, s2):
        self.fout.write('\"%s\" \"%s\"\n' % (s1, s2))

    def gen_a_random_string(self, length):
        ret = []
        for _ in range(length):
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)])
        ret2 = []
        for _ in range(length):
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)])

        self.output_str(''.join(ret), ''.join(ret2))

    def gen_correct_string(self, length):
        ret = []
        for _ in range(length):
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)])
        rn = random.randint(0, len(ret) - 1)
        ret2 = ret[rn:] + ret[:rn]
        self.output_str(''.join(ret), ''.join(ret2))

    def gen_series_string(self, nsamp, large_L):
        for _ in range(int(nsamp/2)):
            l = random.randint(1, large_L)
            self.gen_a_random_string(l)
            self.gen_correct_string(l)

    def gen_special_case(self):
        print(type(''))
        self.output_str("waterbottle", "bottlewater")
        self.output_str("aa", "aba")
        self.output_str('', '')
        self.output_str("a", "a")
        self.output_str("ab", "ba")
        self.output_str("aba", "bab")

    def gen_small_cases(self):
        self.gen_series_string(N_SMALL_SAMPLE, L_SMALL)

    def gen_large_cases(self):
        self.gen_series_string(N_LARGE_SAMPLE, L_LARGE)

    def gen_boundary_string(self):
        self.gen_a_random_string(L_BOUDERY)
        self.gen_correct_string(L_BOUDERY)

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
            s1, s2 = line.split(' ')
            s1 = s1.replace('\"', '')
            s2 = s2.replace('\"', '').replace('\n', '')
            if solution.isFlipedString(s1, s2):
                fout.write('true')
            else:
                fout.write('false')
            fout.write('\n')


if __name__ == '__main__':
    tg = FilppedStringTestCaseGenerator('input_file')
    tg.gen_all_cases()
    get_res('output_file', 'input_file')
