import random
import json
from cyaron import Graph


AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 100000


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


class DrawLineTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output

    def __graph2list(self, graph):
        graph = [x for e in graph.edges for x in e]
        return list(map(lambda x: [x.start - 1, x.end - 1], graph))

    def gen_bad_cases(self, length):
        hei = random.randint(1, 10)
        w = random.randint(1, max(int(length/10), 1)) * 32
        length = int(w/32) * hei
        x1 = random.randint(0, 30)
        x2 = random.randint(x1, 31)
        y = random.randint(0, hei - 1)
        self.output(length)
        self.output(w)
        self.output(x1)
        self.output(x2)
        self.output(y)

    def gen_random_cases(self, length):
        hei = random.randint(1, 10)
        w = random.randint(1, max(int(length/10), 1)) * 32
        length = int(w/32) * hei
        x1 = random.randint(0, w - 2)
        x2 = random.randint(x1, w - 1)
        y = random.randint(0, hei - 1)
        self.output(length)
        self.output(w)
        self.output(x1)
        self.output(x2)
        self.output(y)

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class TestCaseGenerator:

    def __init__(self, file_out='input_file', case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')
        self.listGen = DrawLineTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(1, 32, 30, 31, 0)
        self.output(3, 96, 0, 95, 0)

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


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    #get_res('input_file', 'output_file')
