#include<stdio.h>
#include<stdlib.h>

//循环
int Fibonacci_1(int n) {
	int fib[100] = { 0,1 };  //使用静态数组保存数列
	
	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n ];
}


//递归
int Fibonacci_2(int n) {
	if (n <= 1){
		return n;
	}
	else
	{
		return Fibonacci_2(n - 1) + Fibonacci_2(n - 2);
	}
}

//动态规划
int Fibonacci_3(int i, int* a)
{
	if (i <= 1){
		return i;
	}
	if (a[i] != 0){
		return a[i];
	}
	else{
		a[i] = Fibonacci_3(i - 1, a) + Fibonacci_3(i - 2, a);
	}
}

int main() {
	int result = Fibonacci_1(5);
	/*int result = Fibonacci_2(5);*/
	//从第零项开始
	printf("斐波那契数列的第%d项为:%d\n", 5,result);

	int n;
	scanf_s("%d", &n);
	//通过malloc创建动态数组，用来保存数列
	int* a = (int*)malloc((n + 1) * sizeof(int));
	a[0] = 0;
	a[1] = 1;
	Fibonacci_3(n, a); // 执行完后，斐波那契数列的前n项都保存到数组a中了
	free(a); //与malloc配套使用


	return 0;
}
