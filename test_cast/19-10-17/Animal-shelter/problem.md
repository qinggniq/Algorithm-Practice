动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如`enqueue`、`dequeueAny`、`dequeueDog`和`dequeueCat`。允许使用Java内置的LinkedList数据结构。

<p> <strong>示例1:</strong></p>
<pre>
<strong> 输入</strong>：
['AnimalShelf', 'enqueue', 'enqueue', 'dequeueCat', 'dequeueDog', 'dequeueAny']
[null, [0, 0], [1, 0],null, null,null]
<strong> 输出</strong>：
[null, null, null, [0, 0], [], [1, 0]]
</pre>

<p> <strong>示例2:</strong></p>
<pre>
<strong> 输入</strong>：['AnimalShelf', 'enqueue', 'enqueue', 'enqueue', 'dequeueDog', 'dequeueCat', 'dequeueAny']
[null, [0, 0], [1, 0], [2, 1], null, null,null]
<strong> 输出</strong>：
[null,null, null, null, [0, 0], [2, 1], [1, 0]]



