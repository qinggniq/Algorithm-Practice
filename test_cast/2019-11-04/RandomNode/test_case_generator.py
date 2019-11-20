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
L_BOUDERY = 100000


class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.right = None
        self.left = None
        self.leftCnt = 0
        self.rightCnt = 0


class Solution:
    def __init__(self):
        self.root = None

    def __insert(self, node: TreeNode, val: int) -> TreeNode:
        if node == None:
            node = TreeNode(val)
        else:
            if val > node.val:
                node.right = self.__insert(node.right, val)
                node.rightCnt += 1
            else:
                node.left = self.__insert(node.left, val)
                node.leftCnt += 1
        return node

    def insert(self, val: int):
        if self.root == None:
            self.root = TreeNode(val)
        else:
            self.__insert(self.root, val)

    def __find(self, node: TreeNode, key: int) -> int:
        if node == None or node.val == key:
            return -1 if node == None else node.val
        else:
            if node.val > key:
                return self.__find(node.right, key)
            else:
                return self.__find(node.left, key)

    def find(self, val: int) -> TreeNode:
        return self.__find(self.root, val)

    def __findMax(self, node: TreeNode) -> TreeNode:
        if node.right == None:
            return node
        else:
            return self.__findMax(node.right)

    def __delete(self, node: TreeNode, key: int) -> TreeNode:
        if node == None:
            return node
        if key < node.val:
            node.left = self.__delete(node.left, key)
            node.leftCnt -= 1
            return node
        if key > node.val:
            node.right = self.__delete(node.right, key)
            node.rightCnt -= 1
            return node
        # no children
        if node.left is None and node.right is None:
            node = None
            return None
        # no left child
        if node.left is None and node.right is not None:
            node = node.right
            return node
        # nonothild
        if node is not None and node.right is None:
            node = node.left
            return node
        # two children
        if node is not None and node.right is not None:
            leftMaxNode = self.__findMax(node.left)
            node.val = leftMaxNode.val
            node.left = self.__delete(node.left, leftMaxNode.val)
            node.leftCnt -= 1
            return node

    def delete(self, val: int):
        self.__delete(self.root, val)

    def __getRandomNode(self, node: TreeNode) -> int:
        if node == None:
            return -1
        tot = node.leftCnt + node.rightCnt + 1
        choice = random.randint(0, tot - 1)
        if choice == node.leftCnt:
            return node.val
        elif choice < node.leftCnt:
            return self.__getRandomNode(node.left)
        else:
            return self.__getRandomNode(node.right)

    def getRandomNode(self) -> int:
        return self.__getRandomNode(self.root)


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


class StackOfPlatesTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output):
        self.output = output
        self.operators = ['insert',
                          'find', 'delete', 'getRandomNode']

    def gen_bad_cases(self, length):
        ops = ['GetRandomNode']
        vals = [[]]
        vis = set()
        badType = random.randint(0, 1)
        if badType == 0:
            for _ in range(int(length/2)):
                ops.append(self.operators[0])
                candidate = random.randint(0, length)
                while candidate in vis:
                    candidate = random.randint(0, length)
                vis.add(candidate)
                vals.append([candidate])
            for val in vis:
                ops.append(self.operators[2])
                vals.append([val])
        else:
            for _ in range(int(length/2)):
                ops.append(self.operators[0])
                candidate = random.randint(0, length)
                while candidate in vis:
                    candidate = random.randint(0, length)
                vals.append([candidate])
                vis.add(candidate)
            for val in vis:
                ops.append(self.operators[3])
                vals.append([])
        self.output(ops, vals)

    def gen_random_cases(self, length):
        ops = ['GetRandomNode']
        vals = [[]]
        vis = set()
        for _ in range(int(length)):
            op = random.randint(0, len(self.operators) - 1)
            ops.append(self.operators[op])
            if op == 0:
                candidate = random.randint(0, length * 100)
                while candidate in vis:
                    candidate = random.randint(0, length * 100)
                vis.add(candidate)
                vals.append([candidate])
            elif op == 2:
                if len(vis) == 0:
                    ops.pop()
                    continue
                else:
                    c = random.sample(vis, 1)[0]
                    # print(vis)
                    vis.remove(c)
                    vals.append([c])
            elif op == 1:
                if len(vis) == 0:
                    vals.append([random.randint(0, length)])
                else:
                    if random.randint(0, 1) == 0:
                        vals.append([random.randint(0, len(vis))])
                    else:
                        vals.append([random.sample(vis, 1)[0]])
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
        self.listGen = StackOfPlatesTestcaseGenerator(self.output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def gen_special_case(self):
        self.output(['GetRandomNode', 'insert', 'insert', 'getRandomNode',
                     'getRandomNode', 'getRandomNode'], [[], [1], [2], [], [], []])

        self.output(['GetRandomNode', 'insert', 'insert', 'insert',
                     'delete', 'find', 'getRandomNode'], [[], [1], [2], [3], [1], [1], []])

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
            #print(type(ops), len(ops), len(vals))
            ret = []
            sol = None
            for i in range(len(ops)):
                if ops[i] == 'GetRandomNode':
                    sol = Solution()
                    ret.append(None)
                elif ops[i] == 'insert':
                    sol.insert((vals[i][0]))
                    ret.append(None)
                elif ops[i] == 'find':
                    ret.append(sol.find(vals[i][0]))
                elif ops[i] == 'delete':
                    sol.delete(vals[i][0])
                    ret.append(None)
                elif ops[i] == 'getRandomNode':
                    ret.append(sol.getRandomNode())
            # print(ops, ret)
            json.dump(ret, fout)
            fout.write("\n")


if __name__ == "__main__":
    gen = TestCaseGenerator()
    gen.gen_all_cases()
    get_res('input_file', 'output_file')
