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


class Solution:
    def findWhetherExistsPath(self, n: int, graph, start: int, target: int) -> bool:
        g = [[] for x in range(n)]
        q = []
        vis = set()
        for e in graph:
            g[e[0]].append(e[1])
        q.append(start)
        vis.add(start)

        while len(q) != 0:
            now = q.pop(0)
            if now == target:
                return True
            for nxt in g[now]:
                if nxt not in vis:
                    vis.add(start)
                    q.append(nxt)
        return False


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


class InterNodeAccessTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['enqueue',
                          'dequeueAny', 'dequeueCat', 'dequeueDog']

    def __graph2list(self, graph):
        graph = [x for e in graph.edges for x in e]
        return list(map(lambda x: [x.start - 1, x.end - 1], graph))

    def gen_bad_cases(self, length):
        n = length  # 点数
        m = length  # 边数 稀疏图
        graph = Graph.DAG(n, m)
        self.output(length)
        self.output(self.__graph2list(graph))
        self.output(0)
        self.output(length - 1)

    def gen_random_cases(self, length):
        n = length
        m = length * min(1, int(length/2))

        graph = Graph.DAG(n, m)
        self.output(length)
        self.output(self.__graph2list(graph))
        self.output(random.randint(0, length - 1))
        self.output(random.randint(0, length - 1))

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class TestCaseGenerator:

    def __init__(self, file_out='input_file', case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')
        self.listGen = InterNodeAccessTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(3, [[0, 1], [0, 2], [1, 2], [1, 2]], 0, 2)
        self.output(5, [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [
                    1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], 0, 4)
        self.output(12, [[0, 1], [1, 2], [1, 3], [1, 10], [1, 11], [1, 4], [2, 4], [2, 6], [2, 9], [2, 10], [2, 4], [2, 5], [
                    2, 10], [3, 7], [3, 7], [4, 5], [4, 11], [4, 11], [4, 10], [5, 7], [5, 10], [6, 8], [7, 11], [8, 10]], 2, 3)
        self.output(25, [[0, 1], [0, 3], [0, 10], [0, 18], [1, 2], [1, 7], [1, 11], [1, 12], [2, 4], [2, 5], [2, 13], [2, 16], [3, 6], [
                    3, 8], [4, 9], [5, 17], [7, 20], [7, 22], [8, 10], [10, 19], [11, 15], [13, 14], [14, 21], [15, 23], [19, 24], [20, 22]], 0, 12)

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
        for i in range(0, len(lines), 4):
            n = int(lines[i])
            #n = (json.loads(lines[i]))
            edges = (json.loads(lines[i+1]))
            start = int(lines[i+2])
            end = int(lines[i+3])

            sol = Solution()
            json.dump(sol.findWhetherExistsPath(
                n, edges, start, end), fout)
            fout.write('\n')


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
