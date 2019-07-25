//#include <stdio.h>
//#include <string.h>
//
//int map[11][103] = { 0 };
//int dp[11][103][2] = { 0 };
//
//int Min(int a, int b, int c)
//{
//	if (a <= b)
//	{
//		if (a <= c) return 0;
//		else return 2;
//	}
//	else
//	{
//		if (b <= c) return 1;
//		else return 2;
//	}
//}
//
//int main()
//{
//	int m, n;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = n - 1; j >= 0; j--)
//			{
//				scanf("%d", &map[i][j]);
//			}
//		}
//		for (int j = 0; j < n; j++)
//		{
//			for (int i = 0; i < m; i++)
//			{
//				if (!j) dp[i][j][0] = map[i][j];
//				else
//				{
//					int A[3];
//					if (i == 0)
//					{
//						A[0] = i;
//						A[1] = (i + 1) % m;
//						A[2] = (i + m - 1) % m;
//					}
//					else if (i == m - 1)
//					{
//						A[0] = (i + 1) % m;
//						A[1] = (i + m - 1) % m;
//						A[2] = i;
//					}
//					else
//					{
//						A[0] = (i + m - 1) % m;
//						A[1] = i;
//						A[2] = (i + 1) % m;
//					}
//					int tmp = Min(dp[A[0]][j - 1][0], dp[A[1]][j - 1][0], dp[A[2]][j - 1][0]);
//					dp[i][j][0] = dp[A[tmp]][j - 1][0] + map[i][j];
//					dp[i][j][1] = tmp;
//				}
//			}
//		}
//		int sn = 0;
//		int min = dp[0][n - 1][0];
//		for (int i = 1; i < m; i++)
//		{
//			if (dp[i][n - 1][0] < min)
//			{
//				min = dp[i][n - 1][0];
//				sn = i;
//			}
//		}
//		printf("%d", sn + 1);
//		for (int i = n - 1; i >= 1; i--)
//		{
//			int dir = dp[sn][i][1];
//			if (sn == 0)
//			{
//				if (dir == 1) sn = 1;
//				if (dir == 2) sn = m - 1;
//			}
//			else if (sn == m - 1)
//			{
//				if (dir == 0) sn = 0;
//				if (dir == 1) sn -= 1;
//			}
//			else
//			{
//				if (dir == 0) sn -= 1;
//				else if (dir == 2) sn += 1;
//			}
//			printf(" %d", sn + 1);
//		}
//		printf("\n%d\n", min);
//		memset(dp, 0, sizeof(dp));
//	}
//	return 0;
//}