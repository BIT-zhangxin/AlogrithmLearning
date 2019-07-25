//#include <stdio.h>
//
//int f(int M)
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		if ((i*M + 1) % (M - 1) == 0) return i;
//	}
//}
//
//int main()
//{
//	int N, M;
//	scanf("%d%d", &N, &M);
//	if (N == 1)
//	{
//		printf("%d\n", M-1);
//		printf("%d\n", M+1);
//		return 0;
//	}
//	int F = f(M);
//	int x0 = F;
//	for (int i = 1; i < N; i++)
//	{
//		x0 = (M - 1)*x0 + F;
//	}
//	x0 -= F;
//	if (M == 2) x0 = 1;
//	int xn = x0;
//	for (int i = 0; i < N; i++)
//	{
//		xn = xn / (M - 1)*M + 1;
//	}
//	printf("%d\n", x0);
//	printf("%d\n", xn);
//	return 0;
//}