## 57. 插入区间
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

#### 示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]

输出：[[1,5],[6,9]]

------------

用指针去扫 intervals，最多可能有三个阶段：

不重叠的绿区间，在蓝区间的左边


有重叠的绿区间

不重叠的绿区间，在蓝区间的右边
