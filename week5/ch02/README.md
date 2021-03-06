## 希尔排序
### 概念及介绍
希尔排序(Shell Sort)是插入排序的一种，它是针对直接插入排序算法的改进。

希尔排序又称缩小增量排序，因 DL.Shell 于 1959 年提出而得名。

它通过比较相距一定间隔的元素来进行，各趟比较所用的距离随着算法的进行而减小，直到只比较相邻元素的最后一趟排序为止。
### 适用说明
希尔排序时间复杂度是 O(n^(1.3-2))，空间复杂度为常数阶 O(1)。

希尔排序没有时间复杂度为 O(n(logn)) 的快速排序算法快 ，因此对中等大小规模表现良好，

但对规模非常大的数据排序不是最优选择，总之比一般 O(n^2 ) 复杂度的算法快得多。
