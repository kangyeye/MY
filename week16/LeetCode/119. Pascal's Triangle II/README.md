## 119. 杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。



 

#### 示例 1:

输入: rowIndex = 3  

输出: [1,3,3,1]

-------------
#### 方法一： 
空间 vector<vector<int>> C(rowIndex + 1)
#### 方法二： 
空间  vector<int> pre, cur滚动数组
#### 方法三： 
空间vector<int> row(rowIndex + 1) 

倒序计算 可以避免前面的数字被覆盖
