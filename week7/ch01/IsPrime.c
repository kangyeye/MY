#define HugeInt long
HugeInt Witness(HugeInt a,HugeInt i,HugeInt N) {
	//a为生成的随机数，a^i == 1(mod P)
	HugeInt X, Y;
	if (i == 0)
		return 1;
	X = Witness(a, i / 2, N);
	if (X == 0)
		return 0;
	Y = (X*X) % N;
	if (Y == 1 && X != 1 && X != N - 1)
		return 0;
	if (i % 2 != 0)
		Y = (a*Y) % N;
	return Y;
}

//判断 N 是否为素数
int IsPrime(HugeInt N) {
	//使用随机数算法，生成一个 大于0小于N的数
	return Witness(Random() % N, N - 1, N) == 1;
}
