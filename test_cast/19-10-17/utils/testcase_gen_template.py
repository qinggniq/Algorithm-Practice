import random

AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 20000


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
    def gen_a_unsutiable_compress_string(self, length):
        ret = []
        i = 0
        while i < length:
            times = min(max(1, random.randint(0, 3)), length - i)
            i += times
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)]*times)
        self.output(''.join(ret))

    def gen_correct_string(self, length):
        ret = []
        for _ in range(length):
            ret.append(AVAILABLE_CHARS[random.randint(
                0, len(AVAILABLE_CHARS) - 1)])
        rn = random.randint(0, len(ret) - 1)
        ret2 = ret[rn:] + ret[:rn]
        self.output(''.join(ret), ''.join(ret2))

    def gen_series_string(self, nsamp, large_L):
        for _ in range(int(nsamp/2)):
            l = random.randint(1, large_L)
            self.gen_a_random_string(l)
            self.gen_a_unsutiable_compress_string(l)


class ListTestcaseGenerator():
    def __init__(self, output):
        self.output = output

    def gen_a_random_array(self, length, rate=0.5):
        ret = []
        i = 0
        uppper = int(length * rate)
        while i < length:
            ret.append(random.randint(0, uppper))
            i += 1
        self.output(ret)

    def gen_series_array(self, nsamp, large_L):
        for _ in range(int(nsamp)):
            l = random.randint(1, large_L)
            self.gen_a_random_array(l)


class TestCaseGenerator:

    def __init__(self, file_out, case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')

    def output(self, *params):
        for para in params:
            self.fout.write('\"%s\"\n' % str(para))

            # self.gen_correct_string(l)

    def gen_special_case(self):
        pass

    def gen_small_cases(self):
        # self.gen_series_string(N_SMALL_SAMPLE, L_SMALL)
        pass

    def gen_large_cases(self):
        # self.gen_series_string(N_LARGE_SAMPLE, L_LARGE)
        pass

    def gen_boundary_case(self):
        # self.gen_a_random_string(L_BOUDERY)
        # self.gen_a_unsutiable_compress_string(L_BOUDERY)
        pass

    def gen_all_cases(self):
        self.gen_special_case()
        self.gen_small_cases()
        self.gen_large_cases()
        self.gen_boundary_case()
        self.fout.close()
