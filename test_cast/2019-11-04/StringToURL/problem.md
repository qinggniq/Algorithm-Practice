URL化。编写一种方法，将字符串中的空格全部替换为` %20`。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用`Java`实现的话，请使用字符数组实现，以便直接在数组上操作。）

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>："Mr John Smith    ", 13
<strong> 输出</strong>："Mr%20John%20Smith"
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>："               ", 15
<strong> 输出</strong>："%20%20%20%20%20"
</pre>

<p><strong>提示：</strong></p>
1. 字符串长度在[0, 500000]范围内。
