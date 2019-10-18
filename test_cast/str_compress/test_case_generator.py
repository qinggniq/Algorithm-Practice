import random

AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 50000


class Solution:
    def compressString(self, S: str):
        if len(S) <= 2:
            return S
        cnt = 1
        ans = ""
        for i in range(1, len(S)):
            if S[i] == S[i-1]:
                cnt += 1
            else:
                ans += S[i-1] + str(cnt)
                cnt = 1
        ans += S[-1] + str(cnt)
        return ans if len(ans) < len(S) else S


class FilppedStringTestCaseGenerator:

    def __init__(self, file_out, case_num=20):

        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')

    def output_str(self, s):
        self.fout.write('\"%s\"\n' % s)

    def gen_a_random_string(self, length):
        ret = []
        i = 0
        while i < length:
            times = min(random.randint(0, int(length/10+1)), length - i)
            i += times
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)]*times)
        self.output_str(''.join(ret))

    # generate a string that not suitable to compress
    def gen_a_unsutiable_compress_string(self, length):
        ret = []
        i = 0
        while i < length:
            times = min(max(1, random.randint(0, 3)), length - i)
            i += times
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)]*times)
        self.output_str(''.join(ret))
    # def gen_correct_string(self, length):
    #     ret = []
    #     for _ in range(length):
    #         ret.append(AVAILABLE_CHARS[random.randint(
    #             0, len(AVAILABLE_CHARS) - 1)])
    #     rn = random.randint(0, len(ret) - 1)
    #     ret2 = ret[rn:] + ret[:rn]
    #     self.output_str(''.join(ret), ''.join(ret2))

    def gen_series_string(self, nsamp, large_L):
        for _ in range(int(nsamp/2)):
            l = random.randint(1, large_L)
            self.gen_a_random_string(l)
            self.gen_a_unsutiable_compress_string(l)
            # self.gen_correct_string(l)

    def gen_special_case(self):
        print(type(''))
        self.output_str("aabcccccaa")
        self.output_str("abbccd")
        self.output_str('')
        self.output_str("a")
        self.output_str("bb")
        self.output_str("ccc")
        self.output_str("bbaaacc")
        self.output_str("bbbac")

    def gen_small_cases(self):
        self.gen_series_string(N_SMALL_SAMPLE, L_SMALL)

    def gen_large_cases(self):
        self.gen_series_string(N_LARGE_SAMPLE, L_LARGE)

    def gen_boundary_string(self):
        self.gen_a_random_string(L_BOUDERY)
        self.gen_a_unsutiable_compress_string(L_BOUDERY)

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
            line = line.replace('\"', '').replace('\n', '')
            fout.write(str(solution.compressString(line)))
            fout.write('\n')


if __name__ == '__main__':
    tg = FilppedStringTestCaseGenerator('input_file')
    tg.gen_all_cases()
    get_res('output_file', 'input_file')
