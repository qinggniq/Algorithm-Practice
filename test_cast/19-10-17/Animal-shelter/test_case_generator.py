import random
import json


AVAILABLE_CHARS = [chr(ord('a')+i) for i in range(26)
                   ]
AVAILABLE_CHARS.extend([chr(ord('A')+i) for i in range(26)])
RANDOM_SEED = 50
N_SMALL_SAMPLE = 15
N_LARGE_SAMPLE = 9
L_SMALL = 100
L_LARGE = 1000
L_BOUDERY = 20000


class Solution:
    def __init__(self):
        self.catQueue = []
        self.dogQueue = []
        self.time = 0

    def enqueue(self, animal: list):
        if animal[1]:
            self.dogQueue.append((animal, self.time))
        else:
            self.catQueue.append((animal, self.time))
        self.time += 1

    def dequeueAny(self) -> list:
        if len(self.dogQueue) == 0 and len(self.catQueue) == 0:
            return []

        if len(self.dogQueue) == 0:
            return self.catQueue.pop(0)[0]
        if len(self.catQueue) == 0:
            return self.dogQueue.pop(0)[0]
        if self.dogQueue[0][1] <= self.catQueue[0][1]:
            return self.dogQueue.pop(0)[0]
        else:
            return self.catQueue.pop(0)[0]

    def dequeueDog(self) -> list:
        if len(self.dogQueue) != 0:
            return self.dogQueue.pop(0)[0]
        return []

    def dequeueCat(self) -> list:
        if len(self.catQueue) != 0:
            return self.catQueue.pop(0)[0]
        return []


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


class AnimalShelfTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['enqueue',
                          'dequeueAny', 'dequeueCat', 'dequeueDog']

    def gen_bad_cases(self, length):
        ops = ['AnimalShelf']
        vals = [None]
        cnt = 0
        for _ in range(int(length/2)):
            ops.append(self.operators[0])
            vals.append([cnt, random.randint(0, 1)])
            cnt += 1
        for _ in range(int(length/2)):
            ops.append(self.operators[1])
            vals.append(None)
        self.output(ops, vals)

    def gen_random_cases(self, length):
        ops = ['AnimalShelf']
        vals = [None]
        cnt = 0
        for _ in range(int(length)):
            op = random.randint(0, len(self.operators) - 1)
            ops.append(self.operators[op])
            if op == 0:
                vals.append([cnt, random.randint(0, length)])
                cnt += 1
            else:
                vals.append(None)
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
        self.listGen = AnimalShelfTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(['AnimalShelf', 'enqueue', 'enqueue', 'dequeueCat', 'dequeueDog', 'dequeueAny']
                    )
        self.output([None, [0, 0], [1, 0], None, None, None])

        self.output(['AnimalShelf', 'enqueue', 'enqueue', 'enqueue',
                     'dequeueDog', 'dequeueCat', 'dequeueAny'])
        self.output([None, [0, 0], [1, 0], [2, 1], None, None, None])

        self.output(['AnimalShelf', 'enqueue', 'enqueue', 'enqueue', 'dequeueAny', 'dequeueAny']
                    )
        self.output([None, [0, 0], [1, 1], [2, 0], None, None])

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
            print(type(ops), len(ops), len(vals))
            ret = []
            sol = Solution()
            for i in range(len(ops)):
                if ops[i] == 'AnimalShelf':
                    ret.append(None)
                elif ops[i] == 'enqueue':
                    sol.enqueue((vals[i]))
                    ret.append('null')
                elif ops[i] == 'dequeueCat':
                    ret.append(sol.dequeueCat())
                elif ops[i] == 'dequeueDog':
                    ret.append(sol.dequeueDog())
                elif ops[i] == 'dequeueAny':
                    ret.append(sol.dequeueAny())
            #print(ops, ret)
            json.dump(ret, fout)


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
