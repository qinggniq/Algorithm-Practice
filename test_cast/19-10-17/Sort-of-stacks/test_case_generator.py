import json
import random
from .solution import Solution
from utils import ListTestcaseGenerator, TestCaseGenerator, N_SMALL_SAMPLE, N_LARGE_SAMPLE, L_LARGE, L_SMALL, L_BOUDERY


class SortStackListTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['push', 'pop', 'peek', 'isEmpty']

    def gen_bad_cases(self, length):
        ops = ['SortedStack']
        vals = ['null']
        for i in range(int(length/2)):
            ops.append(self.operators[0])
            vals.append(i)
        for i in range(int(length/2)):
            ops.append(self.operators[1])
            vals.append(i)
        self.output(ops, vals)

    def gen_random_cases(self, length):
        ops = ['SortedStack']
        vals = ['null']
        for _ in range(int(length)):
            op = random.randint(0, len(self.operators) - 1)
            ops.append(self.operators[op])
            if op == 1:
                vals.append(random.randint(0, length))
            else:
                vals.append('null')
        self.output(ops, vals)

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class SortStackTestcaseGener(TestCaseGenerator):
    def __init__(self):
        self.listGenerator = SortStackListTestcaseGenerator(self.output)

    def gen_special_case(self):
        operators = ['SortedStack', 'push', 'push', 'peek', 'pop', 'peek']
        input_vals = ['null', '1', '2', 'null', 'null', 'null', 'null']
        self.output(operators, input_vals)
        operators = ['SortedStack', 'pop', 'pop', 'push', 'pop', 'isEmpty']
        input_vals = ['null', 'null', 'null', '1', 'null', 'null']
        self.output(operators, input_vals)
        operators = ['SortedStack', 'pop', 'pop',
                     'push', 'push', 'peek', 'peek']
        input_vals = ['null', 'null', 'null', '1', '2', 'null', 'null', 'null']
        self.output(operators, input_vals)

    def gen_small_cases(self):
        self.listGenerator.gen_series_cases(N_SMALL_SAMPLE, L_SMALL)

    def gen_large_cases(self):
        self.listGenerator.gen_series_cases(N_LARGE_SAMPLE, L_LARGE)

    def gen_boundary_case(self):
        self.listGenerator.gen_bad_cases(L_BOUDERY)


solution = Solution()


def get_res(file_out, file_in):
    lines = []
    with open(file_in, "r") as fin:
        lines = fin.readlines()
    with open(file_out, "w") as fout:
        for i in range(0, len(lines), 2):
            ops = json.loads(lines[i])
            res = json.loads(lines[i+1])
            fout.write(str(solution.removeDup(arr)))
            fout.write('\n')