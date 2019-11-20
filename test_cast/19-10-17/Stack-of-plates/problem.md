堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构`SetOfStacks`，模拟这种行为。`SetOfStacks`应该由多个栈组成，并且在前一个栈填满时新建一个栈。此外，`SetOfStacks.push()`和`SetOfStacks.pop()`应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。
进阶：实现一个`popAt(int index)`方法，根据指定的子栈，执行pop操作。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：
['StackOfPlates', 'push', 'push', 'pop','pop', 'pop']
[2, 1, 2, None, None, None]
<strong> 输出</strong>：
[null, null, null, 2, 1, -1]
<strong> 说明</strong>：当栈中没有元素时，`pop`返回-1
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：
['StackOfPlates', 'push', 'push', 'push', 'popAt', 'popAt', 'popAt'],
 [2, 1, 2, 3, 0, 0, 0]
<strong> 输出</strong>：
[null, null, null, null, 2, 1, -1]
</pre>