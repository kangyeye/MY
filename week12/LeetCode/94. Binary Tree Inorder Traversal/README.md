## 94. 二叉树的中序遍历 

给定一个二叉树的根节点 root ，返回它的 中序 遍历。

#### 示例 1：

输入：root = [1,null,2,3]

输出：[1,3,2]

#### 示例 2：

输入：root = []

输出：[]

#### 示例 3：

输入：root = [1]

输出：[1]

---------
## Tips:
#### Morris 中序遍历

思路与算法

Morris 遍历算法是另一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 O(1)O(1)。

Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 xx）：

如果 xx 无左孩子，先将 xx 的值加入答案数组，再访问 xx 的右孩子，即 x = x.\textit{right}x=x.right。

如果 xx 有左孩子，则找到 xx 左子树上最右的节点（即左子树中序遍历的最后一个节点，xx 在中序遍历中的前驱节点），

我们记为{predecessor}predecessor。

根据{predecessor}predecessor 的右孩子是否为空，进行如下操作。

如果 {predecessor}predecessor 的右孩子为空，则将其右孩子指向 xx，然后访问 xx 的左孩子，即 x = x.{left}x=x.left。

如果 {predecessor}predecessor 的右孩子不为空，则此时其右孩子指向 xx，说明我们已经遍历完 xx 的左子树，

我们将{predecessor}predecessor 的右孩子置空，将 xx 的值加入答案数组，然后访问 xx 的右孩子，即 x = x.{right}x=x.right。

重复上述操作，直至访问完整棵树。
