import random


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
