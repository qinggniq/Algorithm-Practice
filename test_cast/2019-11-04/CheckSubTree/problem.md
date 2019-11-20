检查子树。你有两棵非常大的二叉树：t1，有几万个节点；t2，有几万个节点。设计一个算法，判断T2是否为T1的子树。

如果T1有这么一个节点n，其子树与T2一模一样，则T2为T1的子树，也就是说，从节点n处把树砍断，得到的树与T2完全相同。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：t1 = [1, 2, 3], t2 = [2]
<strong> 输出</strong>：true
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：t1 = [1, null, 2, 4], t2 = [3, 2]
<strong> 输出</strong>：false
</pre>

<p><strong>提示：</strong></p>

1. 数的节点数目范围为[0, 50000]。