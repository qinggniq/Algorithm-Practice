栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek和isEmpty。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：
['SortedStack', 'push', 'push', 'peek', 'pop', 'peek']
['null', '1', '2', 'null', 'null', 'null', 'null']
<strong> 输出</strong>：
[null, null, null, [0, 0], [], [1, 0]]
<strong> 说明</strong>：输入`[id, type]`，`id`代表宠物编号，`type`代表宠物种类，其中0代表猫，1代表狗
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>： 
['SortedStack', 'pop', 'pop', 'push', 'pop', 'isEmpty']
['null', 'null', 'null', '1', 'null', 'null']
<strong> 输出</strong>：
[null,null, null, null, [0, 0], [2, 1], [1, 0]]
</pre>

<p> <strong>说明:</strong></p>
1. 栈中的元素数目在[0, 5000]范围内。
