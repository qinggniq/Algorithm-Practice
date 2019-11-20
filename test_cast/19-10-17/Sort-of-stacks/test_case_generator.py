
import json
import random
import os
import sys


AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 5000


class Solution:
    def __init__(self):
        self.st1 = []
        self.st2 = []

    def push(self, val: int):
        while len(self.st1) > 0 and val > self.st1[-1]:
            self.st2.append(self.st1[-1])
            self.st1.pop()
        self.st1.append(val)
        while len(self.st2) > 0:
            self.st1.append(self.st2[-1])
            self.st2.pop()

    def pop(self):
        if not self.isEmpty():
            self.st1.pop()

    def peek(self):
        if not self.isEmpty():
            return self.st1[-1]
        return -1

    def isEmpty(self):
        return len(self.st1) == 0


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


class SortStackListTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['push', 'pop', 'peek', 'isEmpty']

    def gen_bad_cases(self, length):
        ops = ['SortedStack']
        vals = [[]]
        for i in range(int(length/2)):
            ops.append(self.operators[0])
            vals.append([i])
        for i in range(int(length/2)):
            ops.append(self.operators[1])
            vals.append([])
        self.output(ops, vals)

    def gen_random_cases(self, length):
        ops = ['SortedStack']
        vals = [[]]
        for _ in range(int(length)):
            op = random.randint(0, len(self.operators) - 1)
            ops.append(self.operators[op])
            if op == 0:
                vals.append([random.randint(0, length)])
            else:
                vals.append([])
        self.output(ops, vals)

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class TestCaseGenerator:

    def __init__(self, file_out='input_file', case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
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


class SortStackTestcaseGener(TestCaseGenerator):
    def __init__(self):
        TestCaseGenerator.__init__(self)
        self.listGenerator = SortStackListTestcaseGenerator(self.output)

    def gen_special_case(self):
        operators = ['SortedStack', 'push', 'push', 'peek', 'pop', 'peek']
        input_vals = [[], [1], [2], [], [], []]
        self.output(operators, input_vals)
        operators = ['SortedStack', 'pop', 'pop', 'push', 'pop', 'isEmpty']
        input_vals = [[], [], [], [1], [], []]
        self.output(operators, input_vals)
        operators = ['SortedStack', 'pop', 'pop',
                     'push', 'push', 'peek', 'peek']
        input_vals = [[], [], [], [1], [2], [], []]
        self.output(operators, input_vals)

    def gen_small_cases(self):
        self.listGenerator.gen_series_cases(N_SMALL_SAMPLE, L_SMALL)

    def gen_large_cases(self):
        self.listGenerator.gen_series_cases(N_LARGE_SAMPLE, L_LARGE)

    def gen_boundary_case(self):
        self.listGenerator.gen_bad_cases(L_BOUDERY)


def get_res(file_in, file_out):
    lines = []
    with open(file_in, "r") as fin:
        lines = fin.readlines()
    with open(file_out, "w") as fout:
        for i in range(0, len(lines), 2):
            ops = (json.loads(lines[i]))
            vals = (json.loads(lines[i+1]))
            print(type(ops), len(ops), len(vals))
            ret = []
            sol = Solution()
            for i in range(len(ops)):
                if ops[i] == 'SortedStack':
                    ret.append(None)
                elif ops[i] == 'push':
                    sol.push(int(vals[i][0]))
                    ret.append(None)
                elif ops[i] == 'pop':
                    sol.pop()
                    ret.append(None)
                elif ops[i] == 'isEmpty':
                    ret.append(sol.isEmpty())
                elif ops[i] == 'peek':
                    ret.append((sol.peek()))
            # print(ops, ret)
            json.dump(ret, fout)
            fout.write('\n')


if __name__ == "__main__":
    gen = SortStackTestcaseGener()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
