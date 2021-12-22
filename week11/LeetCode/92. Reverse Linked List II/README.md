## 92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 
示例 1：

输入：head = [1,2,3,4,5], left = 2, right = 4

输出：[1,4,3,2,5]

---------------
## Tips:
#### 穿针引线
关键在于链表的分割

![image](https://user-images.githubusercontent.com/87250799/147059056-9093eac2-abf1-4ee6-ada3-6a569807a7ab.png)
#### 头插法
头插法的整个算法流程

![image](https://user-images.githubusercontent.com/87250799/147059339-5c2a0666-9f2a-4b8b-ac08-ea71d1fb3b7f.png)

单独一步的具体实现

![image](https://user-images.githubusercontent.com/87250799/147059465-fef28eea-5024-402f-9e0a-629319932e98.png)

