
# https://my.oschina.net/u/2822116/blog/789374


import random
import json


class Stack:
    def __init__(self):
        self.val = 0
        self.prevIndex = -1


class Solution:

    def __init__(self, cap):
        self.stack = []
        self.cap = cap
        self.array = [Stack()] * cap
        self.topPoints = [-1, -1, -1]
        self.cnt = 0

    def push(self, val: int, stackNum: int):
        if self.cap == self.cnt:
            return
        lastIndex = self.topPoints[stackNum]
        self.topPoints[stackNum] = self.cnt

        self.array[self.topPoints[stackNum]].val = val
        self.array[self.topPoints[stackNum]].prevIndex = lastIndex

        self.cnt += 1

    def pop(self, stackNum: int):
        if self.topPoints[stackNum] == -1:
            return
        self.topPoints[stackNum] = self.array[self.topPoints[stackNum]].prevIndex

    def peek(self, stackNum: int) -> int:
        if self.topPoints[stackNum] == -1:
            return -1

        return self.array[self.topPoints[stackNum]].val

    def isEmpty(self, stackNum: int) -> bool:
        return self.topPoints[stackNum] == -1


AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 20000


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


class TripleInOneTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['push',
                          'pop', 'peek', 'isEmpty']

    def gen_bad_cases(self, length):
        ops = ['TripleInOne']
        vals = [[random.randint(0, max(1, int(length/10))) * 3]]
        cnt = 0
        for _ in range(int(length/2)):
            ops.append(self.operators[0])
            vals.append([random.randint(0, length), random.randint(0, 2)])
            cnt += 1
        for _ in range(int(length/2)):
            ops.append(self.operators[1])
            vals.append([random.randint(0, 2)])
        self.output(ops, vals)

    def gen_random_cases(self, length):
        ops = ['TripleInOne']
        vals = [[random.randint(0, max(1, int(length/10))) * 3]]
        cnt = 0
        for _ in range(int(length)):
            op = random.randint(0, len(self.operators) - 1)
            ops.append(self.operators[op])
            if op == 0:
                vals.append([random.randint(0, length), random.randint(0, 2)])
                cnt += 1
            else:
                vals.append([random.randint(0, 2)])
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
        self.listGen = TripleInOneTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(['TripleInOne', 'push', 'push', 'pop',
                     'pop', 'pop', 'isEmpty'], [[1], [1, 0], [2, 0], [0], [0], [0], [0]])

        self.output(['TripleInOne', 'push', 'push', 'push',
                     'pop', 'pop', 'pop', 'peek'], [[2], [1, 0], [2, 0], [3, 0], [0], [0], [0], [0]])

        # self.output(['StackOfPlates', 'push', 'push', 'push', 'dequeueAny', 'dequeueAny']
        #             )
        # self.output([None, [0, 0], [1, 1], [2, 0], None, None])

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
    with open(file_in, "r") as fin:
        lines = fin.readlines()
    with open(file_out, "w") as fout:
        for i in range(0, len(lines), 2):
            ops = (json.loads(lines[i]))
            vals = (json.loads(lines[i+1]))
            print(ops[:5], vals[:5])
            ret = []
            sol = None
            for i in range(len(ops)):
                if ops[i] == 'TripleInOne':
                    sol = Solution(int(vals[i][0]))
                    print('int')
                    ret.append(None)
                elif ops[i] == 'push':
                    sol.push(vals[i][0], vals[i][1])
                    ret.append(None)
                elif ops[i] == 'pop':
                    ret.append(None)
                    sol.pop(int(vals[i][0]))
                elif ops[i] == 'peek':
                    print(sol)
                    ret.append(sol.peek(vals[i][0]))
                elif ops[i] == 'isEmpty':
                    ret.append(True if sol.isEmpty(vals[i][0]) else False)
            #print(ops, ret)
            json.dump(ret, fout)
            fout.write("\n")


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
