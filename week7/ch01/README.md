### 随机化算法判断素数
#### 根据费马小定理，实现对素数的判断。

其中如果这个算法宣称一个数不是素数，那么我们可以肯定这个数不是素数。
如果算法宣称一个数是素数，那么这个数将以高的概率是素数，而不是100%是素数。

#### 代码实现用到了伪随机数的生成。

产生随机数的算法：线性同余发生器。数x1，x2，…，的生成满足Xi+1 = AXi mod M。

X0的初始值叫做种子seed。



---
费马小定理：如果P是素数，且 0<A<P,那么A^P-1 ≡ 1（mod P）。
如果P是素数，且 0<X<P，那么X^2 ≡ 1（mod P）仅有两个解 X = 1,P-1。 
