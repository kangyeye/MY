#include<stdio.h>
#include<math.h>
using namespace std;

#define SIGN(A) ((A>0)?1:-1)//定义一个符号函数表示正负
int Multiply(int x, int y, int n)
{
    int sign = SIGN(x) * SIGN(y);
    int XR, XL, YR, YL;
    int P1, P2, P3;
    if (x == 0 || y == 0)
        return 0;
    if (n == 1)
        return x * y;
    else
    {
        //计算X和y的各个部分
        XL = x / pow(10, n / 2);
        XR = x - XL * (pow(10, n / 2));
        YL = y / pow(10, n / 2);
        YR = y - YL * (pow(10, n / 2));
        //分治计算
        P1 = Multiply(XL, YL, n - n / 2);
        P2 = Multiply(XR, YR, n / 2);
        P3 = Multiply(XL + XR, YL + YR, n - n / 2);
        return sign * (P1 * pow(10, 2 * floor(n / 2)) + (P3 - P1 - P2) * pow(10, n / 2) + P2);
    }
}
int main()
{
    printf("分治算法求得 1234 * 4567 = ");
    printf("%d\n", Multiply(1234, 4567, 4));
    printf("非分治算法求得 1234 * 4567 = ");
    printf("%d\n", 1234 * 4567);
    return 0;
}
