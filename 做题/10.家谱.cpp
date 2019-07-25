//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int A[205][105] = { 0 };
//
//int main()
//{
//	int N, K;
//	scanf("%d%d", &N, &K);
//	for (int i = 1; i <= K; i++)
//	{
//		A[1][i] = 1;
//	}
//	for (int j = 1; j <= K; j++)
//	{
//		for (int i = 1; i <= N; i += 2)
//		{
//			for (int k = 1; k <= i - 2; k += 2)
//			{
//				A[i][j] = (A[i][j] + A[k][j - 1] * A[i - 1 - k][j - 1]) % 9901;
//			}
//		}
//	}
//	int ans = (A[N][K] - A[N][K - 1]) % 9901;
//	printf("%d\n", ans);
//	return 0;
//}