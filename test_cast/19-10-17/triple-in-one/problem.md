三合一。描述如何只用一个数组来实现三个栈。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[1, [1, 0], [2, 0], 0, 0, 0, 0]
<strong> 输出</strong>：
[null, null, null, null, null, null, "true"]
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[2, [1, 0], [2, 0], [3, 0], 0, 0, 0, 0]
<strong> 输出</strong>：
[null, null, null, null, null, null, null, 2]
</pre>