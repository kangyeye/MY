//动态规划
class Solution {
public:
    int numTrees(int n) {
        vector<int> F(n+1,0); //定义了n+1个整型元素的向量,且给出每个元素的初值为0
        F[0]=1;
        F[1]=1;
        if(n==1){
            return F[1];
        }
        for(int j=2;j<=n;j++){
            for(int i=1;i<=j;i++){
                F[j]=F[j]+F[i-1]*F[j-i];
            }
        }
        return F[n];
    }
};
