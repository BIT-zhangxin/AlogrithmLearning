//#include <cstdio>
//int dp[100][500] = { 1 };
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ans = 0;
//	if (n % 4 == 0 || n % 4 == 3)
//	{
//		int sum = (n + 1) * n / 4;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= sum; j++)
//			{
//				if (i <= j) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
//				else dp[i][j] = dp[i - 1][j];
//			}
//		}
//		ans = dp[n][sum];
//	}
//	printf("%d\n", ans);
//	return 0;
//}