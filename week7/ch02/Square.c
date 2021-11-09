//给定一组不同长度的棍子，判断是否能组成一个正方形
#include<stdio.h>

#define n 8
#define m 4 //正方形的四条边 

int len[n] = { 4,2,2,1,3,1,1,2 };
int sum[m] = { 0 };//用于保存每一条边上的木棍的长度的和 
int flag = 0;
int edge = 0;

int ok() {
	int i;
	for (i = 0; i < m; i++) {
		if (sum[i] != edge) {
			return 0;
		}
	}
	return 1;
}
void nfs(int t) {
	int i;
	if (flag)
		return;
	if (t == n) {
		if (ok()) {
			flag = 1;
		}
		return;
	}
	for (i = 0; i < m; i++) {
		sum[i] += len[t];
		if (sum[i] <= edge) {
			nfs(t + 1);
		}
		sum[i] -= len[t];
	}
}
int main()
{
	int i;
	for (i = 0; i < n; i++) {
		edge += len[i];
	}
	if (edge % m != 0) {
		printf("Yes.\n");
		return 0;
	}
	edge /= m;
	nfs(0);
	if (flag) {
		printf("Yes.\n");
	}
	else {
		printf("No.\n");
	}
	return 0;
}
