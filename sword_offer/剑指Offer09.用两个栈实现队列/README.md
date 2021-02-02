*题目描述*

> 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof

*解法 1*

> 题目要求使用两个栈来实现一个队列，我们先来回顾栈和队列的定义。
>
> - 栈： 只允许在有序的线性集合的一端，称为堆栈顶端，进行加入数据和移除数据的运算。因而按照后进先出（LIFO, Last In First Out）的原理运作。
> - 队列：允许在后端进行插入操作，在前端进行删除操作， 是先进先出（FIFO, First-In-First-Out）的线性表。

> 栈底的元素是队列的头部（front），元素出栈到另一个栈中可以保证第一个栈的栈底元素先出栈，所以我们分别定义两个栈，一个栈负责数据入队，另一栈负责数据出队。
>
>  ``` c++
> stack<int> in_stack;  // 负责数据入队列
> stack<int> out_stack;  // 负责数据出队列
>  ```

> in_stack栈底元素是队列的头部（front），每当out_stack为空时把in_stack的所有的数据出栈，然后入栈到out_stack中（in_stack可以不用把所有的元素出栈到out_stack中，保留1个元素在返回结果时in_stack出栈可以减少一次出栈和一次入栈操作）。
>
> ``` c++
>  if (!out_stack.empty()) {
>    int top = out_stack.top();
>    out_stack.pop();
>    return top;
>  } else {
>    // 将in_stack中的所有元素出栈，保留1个作为结果返回
>    while (in_stack.size() > 1) {
>      out_stack.push(in_stack.top());
>      in_stack.pop();
>    }
>    if (in_stack.size() == 1) {
>      int top = in_stack.top();
>      in_stack.pop();
>      return top;
>    } else {
>      return -1;
>    }
>  }
> ```
>
> 



