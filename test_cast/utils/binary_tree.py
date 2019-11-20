import random


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


def serialize(g):
    if g.n == 0:
        return "[]"

    q = [g.root]
    res = []
    i = 0
    while i < len(q):
        u = q[i]
        i += 1
        if not u:
            res.append("null")
            continue
        res.append(u.val)
        q.append(u.left)
        q.append(u.right)

    while res[-1] == 'null':
        res.pop()
    return f"[{','.join(str(i) for i in res)}]"


if __name__ == '__main__':
    n = 50
    g = BinaryTree(n, left=0.2)
    print(serialize(g))
