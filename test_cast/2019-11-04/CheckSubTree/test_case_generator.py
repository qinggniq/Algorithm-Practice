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
L_BOUDERY = 50000


class default_val_gen:
    def __init__(self):
        self.cnt = 0

    def __call__(self):
        self.cnt += 1
        return self.cnt


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self, n, left=0.5, val_gen=default_val_gen()):
        """
        :param n: 节点数
        :param left: 节点成为左子树的概率
        :param val_gen: 生成节点权值的 callable
        :return:
        """

        self.n = n
        self.root = TreeNode(val_gen()) if n > 0 else None

        can_left = set([self.root])
        can_right = set([self.root])
        for i in range(n - 1):
            pos = random.random()
            v = TreeNode(val_gen())
            if pos <= left:
                u = random.choice(list(can_left))
                can_left.remove(u)
                u.left = v
            else:
                u = random.choice(list(can_right))
                can_right.remove(u)
                u.right = v
            can_left.add(v)
            can_right.add(v)

    def chooseSubTree(self, node, depth):
        if depth == 0 or node == None:
            return node
        choice = random.randint(0, 10)
        if choice == 0 or (node.right == None and node.left == None):
            return node
        elif choice <= 5 and (node.left != None):
            return self.chooseSubTree(node.left, depth)
        else:
            return self.chooseSubTree(node.right, depth)


def serialize(node):
    if node == None:
        return [None]
    q = [node]
    res = []
    i = 0
    while i < len(q):
        u = q[i]
        i += 1
        if not u:
            res.append(None)
            continue
        res.append(u.val)
        q.append(u.left)
        q.append(u.right)

    while res[-1] == None:
        res.pop()
    return res  # f"[{','.join(str(i) for i in res)}]"


class Solution:
    def checkSubTree(self, T1: TreeNode, T2: TreeNode) -> bool:
        def preorder(T: TreeNode, s: str) -> str:
            if T == None:
                s += '#'
                return s
            s += str(T.val) + ' '
            s = preorder(T.left, s)
            s = preorder(T.right, s)
            return s
        return preorder(T2, '') in preorder(T1, '')


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


class CheckSubTreeTestcaseGenerator(ListTestcaseGenerator):
    def __init__(self, output, write_output):
        self.output = output
        self.write_output = write_output

    def gen_bad_cases(self, length):
        n = length  # 二叉树点数
        g1 = BinaryTree(n)
        g2 = BinaryTree(int(n/2))
        self.output(serialize(g1.root))
        self.output(serialize(g2.root))
        self.write_output(Solution().checkSubTree(g1.root, g2.root))

    def gen_random_cases(self, length):
        n = length
        g1 = BinaryTree(n)
        g2 = g1.chooseSubTree(g1.root, int(random.randint(1, n)))
        self.output(serialize(g1.root))
        self.output(serialize(g2))
        self.write_output(Solution().checkSubTree(g1.root, g2))

    def gen_series_cases(self, nsamp, large_L):
        for _ in range(0, int(nsamp), 2):
            l = random.randint(1, large_L)
            self.gen_random_cases(l)
            self.gen_bad_cases(l)


class TestCaseGenerator:

    def __init__(self, file_out='input_file', write_out='output_file', case_num=20):
        random.seed(RANDOM_SEED)
        self.fout = open(file_out, 'w')
        self.fwrite_out = open(write_out, 'w')
        self.listGen = CheckSubTreeTestcaseGenerator(
            self.output, self.write_output)

    def output(self, *params):
        for para in params:
            if type(para) == str:
                self.fout.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fout)
            self.fout.write('\n')
            # self.gen_correct_string(l)

    def write_output(self, *params):
        for para in params:
            if type(para) == str:
                self.fwrite_out.write('\"%s\"' % str(para))
            else:
                json.dump(para, self.fwrite_out)
            self.fwrite_out.write('\n')

    def gen_special_case(self):
        self.output([1, 2, 3], [2])
        self.write_output(True)
        self.output([1, None, 2, 4],  [3, 2])
        self.write_output(False)

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
