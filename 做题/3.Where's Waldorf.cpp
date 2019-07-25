//#include <stdio.h>
//#include <string.h>
//
//char map[55][55];
//int m, n;
//int dx[] = { 0,1,1,1,0,-1,-1,-1 };
//int dy[] = { 1,1,0,-1,-1,-1,0,1 };
//
//int search(int x,int y,int dir,char *p,int len);
//void change(int dimension,char *p);
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d%d", &m, &n);
//		memset(map, 0, sizeof(map));
//		for (int i = 0; i < m; i++)
//		{
//			scanf("%s", map[i]);
//		}
//		change(2, NULL);
//		int num;
//		scanf("%d", &num);
//		for (int k = 0; k < num; k++)
//		{
//			char tmp[55];
//			int rx, ry;
//			scanf("%s", tmp);
//			change(1, tmp);
//			int len = strlen(tmp)-1;
//			for (int i = 0; i < m; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					if (map[i][j] == *tmp)
//					{
//						for (int dir = 0; dir < 8; dir++)
//						{
//							if (i+len*dx[dir]>=0&&i+len*dx[dir]<m&&j+len*dy[dir]>=0&&j+len*dy[dir]<n)
//							{
//								if (search(i, j, dir, tmp + 1, len))
//								{
//									rx = i;
//									ry = j;
//									goto loop;
//								}
//							}
//						}
//					}
//				}
//			}
//			loop:
//			printf("%d %d\n", rx+1, ry+1);
//		}
//		if (T > 0) putchar(10);
//	}
//	return 0;
//}
//
//int search(int x,int y, int dir, char *p, int len)
//{
//	if (len == 0) return 1;
//	if (map[x + dx[dir]][y + dy[dir]] == *p)
//	return search(x + dx[dir], y + dy[dir], dir, p + 1, len - 1);
//	else return 0;
//}
//
//void change(int dimension,char *p)
//{
//	if (dimension == 2)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (map[i][j] >= 'A'&&map[i][j] <= 'Z')
//					map[i][j] += 'a' - 'A';
//			}
//		}
//	}
//	else if (dimension == 1)
//	{
//		while (*p != 0)
//		{
//			if (*p >= 'A'&&*p <= 'Z')
//				*p += 'a' - 'A';
//			p++;
//		}
//	}
//}