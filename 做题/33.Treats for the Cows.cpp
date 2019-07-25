//#include <stdio.h>
//
//int A[2005] = { 0 };
//int dp[2005][2005] = { 0 };
//
//int Max(int a,int b)
//{
//	return (a > b) ? a : b;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	dp[0][0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		dp[i][0] = dp[i - 1][0] + i*A[i];
//	}
//	for (int j = 1; j <= n; j++)
//	{
//		dp[0][j] = dp[0][j - 1] + j*A[n + 1 - j];
//	}
//	int max = Max(dp[n][0],dp[0][n]);
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; i + j <= n; j++)
//		{
//			dp[i][j] = Max(dp[i - 1][j] + (i + j)*A[i], dp[i][j - 1] + (i + j)*A[n + 1 - j]);
//			if (i + j == n)
//			{
//				if (dp[i][j] > max) max = dp[i][j];
//			}
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}