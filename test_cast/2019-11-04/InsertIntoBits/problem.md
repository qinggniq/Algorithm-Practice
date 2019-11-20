插入。给定两个32位的整数`N`与`M`，以及表示比特位置的`i`与`j`。编写一种方法，将`M`插入`N`，使得M从N的第j位开始，到第`i`位结束。假定从`j`位到`i`位足以容纳`M`，也即若M = 10 011，那么j和i之间至少可容纳5个位。例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M。
<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：N = 10000000000, M = 10011, i = 2, j = 6
<strong> 输出</strong>：N = 10001001100
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>： N = 0, M = 11111, i = 0, j = 4
<strong> 输出</strong>：N = 11111
</pre>

