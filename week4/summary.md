## 堆
### 概念
如果有一个关键码的集合K = {k0，k1， k2，…，kn-1}，把它的所有元素按完全二叉树的顺序存储方式存储在一个一维数组中，

并满足：Ki <= K2i+1 且 Ki<=K2i+2 ，则称为小堆(或大堆)。

将根节点最大的堆叫做最大堆或大根堆，根节点最小的堆叫做最小堆或小根堆。
### 性质
1. 堆中某个节点的值总是不大于或不小于其父节点的值;
2. 堆总是一棵完全二叉树。



### 二叉排序树和堆的区别
#### 结构上:
二叉排序树：左子树小于根节点，根节点又小于右子树。

堆（小堆）：根节点小于左右子树，但是左右子树没有大小之分。
#### 作用上:
从上面各自的结构上的分析可得：二叉排序树是用来做查找的，而堆是用来做排序的。

