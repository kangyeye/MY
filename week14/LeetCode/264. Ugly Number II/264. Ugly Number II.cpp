//多路归并（多指针）
class Solution {
public:
    int nthUglyNumber(int n) {
        // ans 用作存储已有丑数（从下标 1 开始存储，第一个丑数为 1）
        vector<int> ans(n+1);
        ans[1] = 1;
        // 由于三个有序序列都是由「已有丑数」*「质因数」而来
        // i2、i3和i5分别代表三个有序序列当前使用到哪一位「已有丑数」下标（起始都指向 1）
        for(int i2=1,i3=1,i5=1,idx=2;idx<=n;idx++){
            // 由 ans[iX] * X 可得当前有序序列指向哪一位
            int a = ans[i2]*2 , b = ans[i3]*3 , c = ans[i5]*5;
            // 将三个有序序列中的最小一位存入「已有丑数」序列，并将其下标后移
            int temp = min(a,min(b,c));
            // 由于可能不同有序序列之间产生相同丑数，
            // 因此只要一样的丑数就跳过（不能使用 else if ）
            if(temp == a) i2++;
            if(temp == b) i3++;
            if(temp == c) i5++;

            ans[idx] = temp;
        }
        return ans[n];
    }
};


优先队列（最小堆）
class Solution {
private:
    vector<int> nums = {2,3,5};
public:
    int nthUglyNumber(int n) {
        unordered_set<long> set;
        priority_queue<long, vector<long>, greater<long>> q;
        set.insert(1L);
        q.push(1L);
        for(int i=1;i<=n;i++){
            long x = q.top();
            q.pop();
            if(i == n){
                return (int)x;
            }
            for(int num : nums){
                long temp = num * x;
                if(set.count(temp) == 0){
                    set.insert(temp);
                    q.push(temp);
                }
            }
        }
        return -1;
    }
};
