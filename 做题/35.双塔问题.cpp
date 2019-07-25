//#include <stdio.h>
//#include <string.h>
//
//int A[105] = { 0 };
//int B[105] = { 0 };
//int dp[105][105] = { 0 };
//int cal(int m, int n);
//
//int max(int a, int b)
//{
//	return (a > b) ? a : b;
//}
//
//int main()
//{
//	int m, n;
//	int T = 1;
//	while (1)
//	{
//		scanf("%d%d", &m, &n);
//		if (!m && !n) return 0;
//		for (int i = 1; i <= m; i++)
//		{
//			scanf("%d", &A[i]);
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &B[i]);
//		}
//		int ans = cal(m, n);
//		printf("Twin Towers #%d\n", T);
//		printf("Number of Tiles : %d\n", ans);
//		T++;
//		memset(dp, 0, sizeof(dp));
//		//memset(A, 0, sizeof(A));
//		//memset(B, 0, sizeof(B));
//	}
//	return 0;
//}
//
//int cal(int m, int n)
//{
//	for (int i = 0; i <= m; i++)
//	{
//		for (int j = 0; j <= n; j++)
//		{
//			if (!i || !j) dp[i][j] = 0;
//			else if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	return dp[m][n];
//}