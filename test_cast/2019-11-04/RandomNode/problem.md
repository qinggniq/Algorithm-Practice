随机节点。你现在要从头开始实现一个二叉树类，该类除了插入（`insert`）、查找（`find`）和删除（`delete`）方法外，需要实现`getRandomNode()`方法用于返回树中的任意节点。该方法应该以相同的概率选择任意的节点。设计并实现`getRandomNode`方法并解释如何实现其他方法。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：
['GetRandomNode', 'insert', 'insert', 'getRandomNode',                     'getRandomNode', 'getRandomNode']
[null, 1, 2, null, null, null]
<strong> 输出</strong>：
[null, null, null, 2, 1, 1]
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：
['GetRandomNode', 'insert', 'insert', 'insert', 'delete', 'find', 'getRandomNode']
[null, 1, 2, 3, 1, 1, null]
<strong> 输出</strong>：
[null, null, null, null, null, 1, 1]
</pre>

<p><strong>提示：</strong></p>

1. 你可以修改`TreeNode`结构。
2. 你的`insert`， `find`，`delete`，`getRandomNode`都需要是$O(logN)$ 的时间复杂度。