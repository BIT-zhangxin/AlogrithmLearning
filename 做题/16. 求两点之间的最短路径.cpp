//#include <cstdio>
//#include <cstring>
//#define INF 10000000
//char city[105][20] = { 0 };
//int vis[105] = { 0 };
//int dis[105] = { 0 };
//int map[105][105] = { 0 };
//int path[105] = { 0 };
//
//void print(int n)
//{
//	if (n == 0)
//	{
//		printf("%s", city[0]);
//		return;
//	}
//	else
//	{
//		print(path[n]);
//		printf("-%s", city[n]);
//	}
//}
//
//int main()
//{
//	int m, n;
//	scanf("%d,%d%*c", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			map[i][j] = (i == j) ? 0 : INF;
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		char tmp;
//		int len = 0;
//		while (1)
//		{
//			scanf("%c", &tmp);
//			if (tmp == ',' || tmp == '\n')
//			{
//				city[i][len] = 0;
//				break;
//			}
//			city[i][len++] = tmp;
//		}
//	}
//	int tmp1, tmp2, tmp3;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("<%d,%d,%d>%*c", &tmp1, &tmp2, &tmp3);
//		map[tmp1][tmp2] = tmp3;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		dis[i] = map[0][i];
//		vis[i] = 0;
//		path[i] = (dis[i] != INF) ? 0 : -1;
//	}
//	vis[0] = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int tmp = INF;
//		int next = 0;
//		for (int j = 0; j < m; j++)
//		{
//			if (!vis[j] && tmp>dis[j])
//			{
//				tmp = dis[j];
//				next = j;
//			}
//		}
//		vis[next] = 1;
//		for (int j = 0; j < m; j++)
//		{
//			if (!vis[j] && dis[j] > dis[next] + map[next][j])
//			{
//				dis[j] = dis[next] + map[next][j];
//				path[j] = next;
//			}
//		}
//	}
//	print(m - 1);
//	putchar(10);
//	return 0;
//}
