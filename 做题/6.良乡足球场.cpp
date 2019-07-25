//#include <stdio.h>
//
//int map[105][105];
//int check(int m, int n);
//
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &map[i][j]);
//		}
//	}
//	int ans = check(m,n);
//	if (ans == 0) printf("NO\n");
//	else printf("YES\n");
//	return 0;
//}
//
//int check(int m, int n)
//{
//	int xmax[105] = { 0 };
//	int ymax[105] = { 0 };
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] > xmax[i]) xmax[i] = map[i][j];
//		}
//	}
//	for (int j = 0; j < n; j++)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			if (map[i][j] > ymax[j]) ymax[j] = map[i][j];
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] < xmax[i] && map[i][j] < ymax[j])
//				return 0;
//		}
//	}
//	return 1;
//}