//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int x, y;
//	int value;
//}node;
//node A[12];
//int dp[1005][1005] = { 0 };
//
//int Max(int a, int b,int c)
//{
//	if (a > b)
//	{
//		if (a > c) return a;
//		else return c;
//	}
//	else
//	{
//		if (b > c) return b;
//		else return c;
//	}
//}
//
//int cmp(const void *a, const void *b)
//{
//	if ((*(node *)a).x != (*(node *)b).x) return (*(node *)a).x - (*(node *)b).x;
//	else if((*(node *)a).y!= (*(node *)b).y) return (*(node *)a).y - (*(node *)b).y;
//	else return (*(node *)b).value - (*(node *)a).value;
//}
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int n, max_x, max_y;
//		scanf("%d%d%d", &n, &max_x, &max_y);
//		int tmp1, tmp2;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d%d%d", &tmp1, &tmp2, &A[i].value);
//			if (tmp1 < tmp2)
//			{
//				A[i].x = tmp1;
//				A[i].y = tmp2;
//			}
//			else
//			{
//				A[i].x = tmp2;
//				A[i].y = tmp1;
//			}
//		}
//		qsort(A, n, sizeof(node), cmp);
//		for (int i = 1; i <= max_x; i++)
//		{
//			for (int j = 1; j <= max_y; j++)
//			{
//				for (int num = 0; num < n; num++)
//				{
//					if (A[num].x <= i&&A[num].y <= j)
//					{
//						dp[i][j] = Max(dp[i][j], 
//						A[num].value + dp[A[num].x][j - A[num].y] + dp[i - A[num].x][j],
//						A[num].value + dp[i][j - A[num].y] + dp[i - A[num].x][A[num].y]);
//						dp[j][i] = dp[i][j];
//					}
//					if (A[num].x <= j&&A[num].y <= i)
//					{
//						dp[i][j] = Max(dp[i][j],
//						A[num].value + dp[A[num].y][j - A[num].x] + dp[i - A[num].y][j],
//						A[num].value + dp[i][j - A[num].x] + dp[i - A[num].y][A[num].x]);
//						dp[j][i] = dp[i][j];
//					}
//				}
//			}
//		}
//		printf("%d\n", dp[max_x][max_y]);
//		memset(dp, 0, sizeof(dp));
//	}
//	return 0;
//}