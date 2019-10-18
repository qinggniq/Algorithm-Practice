字符串轮转。假定有一种`isSubstring`方法，可检查一个单词是否为其他字符串的子串。给定两个字符串`s1`和`s2`，请编写代码检查`s2`是否为`s1`旋转而成，要求只能调用一次`isSubstring`（比如，`waterbottle`是`erbottlewat`旋转后的字符串）。
<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：s1 = "waterbottle", s2 = "erbottlewat"
<strong> 输出</strong>：True
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：s1 = "aa", "aba"
<strong> 输出</strong>：False
</pre>
<p> <strong>说明:</strong></p>
1. 只能调用一次`isSubstring`方法

<p><strong>提示：</strong></p>
1. 字符串长度在[0, 50000]范围内。
2. 你可以假定`isSubstring`方法复杂度为O(n)。
