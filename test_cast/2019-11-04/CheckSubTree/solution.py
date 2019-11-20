class TreeNode:
    def __init__(self, val: int):
        self.left = None
        self.right = None
        self.val = val


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
