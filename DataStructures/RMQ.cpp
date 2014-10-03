//RMQ - <O(NlgN), O(1)> approach (using sparse table)
#include <cstdio>
#define MAXN 1000
#define MAXLOGN 10
int M[MAXN][MAXLOGN];
void Compute_ST(int A[], int N) {
	int i, j;
	for (i = 0; i < N; i++)
		M[i][0] = i;
	for (j = 1; 1 << j <= N ; j++) {
		int sz = 1 << (j - 1); // block's half size
		for (i = 0; i + sz < N; i++) {
			if (A[M[i][j - 1]] <= A[M[i + sz][j - 1]])
				M[i][j] = M[i][j - 1];
			else
				M[i][j] = M[i + sz][j - 1];
		}
	}
}
int RMQ(int A[], int s, int e) {
	int k = 31 - __builtin_clz(e - s + 1); // k = log(e-s+1)
	// http://www.cnblogs.com/nysanier/archive/2011/04/19/2020778.html
	if (A[M[s][k]] <= A[M[e - (1 << k) + 1][k]])
		return A[M[s][k]];
	return A[M[e - (1 << k) + 1][k]];
}
// driver programme
int main() {
	int A[10] = {3, 1, 2, -1, 5, 4, 6, 0, 9, 8};
	Compute_ST(A, 10);
	int s, e;
	scanf("%d %d", & s, & e);
	printf("%d\n", RMQ(A, s, e));
	return 0;
}