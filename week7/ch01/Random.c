#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)
long Seed;
long Random() {
	long Tmpseed;
	Tmpseed = A * (Seed %Q) - R * (Seed / Q);
	if (Tmpseed >= 0) {
		Seed = Tmpseed;
	}
	else {
		Seed = Tmpseed + M;
	}
	return  Seed;
}
void InitSeed(long S) {
	Seed = S;
}
