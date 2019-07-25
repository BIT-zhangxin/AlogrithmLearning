//#include <stdio.h>
//
//int dit[] = { 9,13,21,29,45,61,93,125,189,253,381,509,765,1021 };
//char map[1005][1005] = { 0 };
//int x = 0;
//int y = 0;
//int len_x = 0;
//int len_y = 0;
//
//int f(int, int);
//void set();
//void BFS(int, int, int);
//void print();
//
//int main()
//{
//	int tmp;
//	scanf("%d%d%d", &x, &y, &tmp);
//	if (x == 3 && y == 3)
//	{
//		printf("...\n.Col_Size.\n...\n");
//		return 0;
//	}
//	set();
//	int start_x, start_y, flag = 0;
//	if (y > x) flag = 1;
//	for (int i = 0; i < 14; i++)
//	{
//		if (((x > y) ? x : y) < dit[i])
//		{
//			//i--;
//			if (!flag)
//			{
//				start_x = dit[i] / 2;
//				start_y = dit[i - 1] / 2;
//				len_x = f(2 + (i + 1) % 2, (i + 1) / 2);
//				len_y = f(2 + (i) % 2, (i) / 2);
//			}
//			else
//		 	{
//				start_y = dit[i] / 2;
//				start_x = dit[i - 1] / 2;
//				len_y = f(2 + (i + 1) % 2, (i + 1) / 2);
//				len_x = f(2 + (i) % 2, (i) / 2);
//			}
//			break;
//		}
//	}
//	BFS(start_x, start_y, flag);
//	print();
//	return 0;
//}
//
//void bfs(int flag, int start_x, int start_y, int len)
//{
//	if (len == 0) return;
//	int tmp = len;
//	if (tmp == 2) tmp = 1;
//	else if (tmp % 3) tmp = len / 4 * 3;
//	else tmp = tmp / 3 * 2;
//	if (flag)
//	{
//		for (int i = 1; i <= len; i++)
//		{
//			map[start_x][start_y + i] = '.';
//			map[start_x][start_y - i] = '.';
//		}
//		bfs(flag ^ 1, start_x, start_y + len, tmp);
//		bfs(flag ^ 1, start_x, start_y - len, tmp);
//	}
//	else
//	{
//		for (int i = 1; i <= len; i++)
//		{
//			map[start_x + i][start_y] = '.';
//			map[start_x - i][start_y] = '.';
//		}
//		len_x /= 2;
//		bfs(flag ^ 1, start_x + len, start_y, tmp);
//		bfs(flag ^ 1, start_x - len, start_y, tmp);
//	}
//}
//
//void BFS(int start_x, int start_y, int flag)
//{
//	map[start_x][start_y] = 'Col_Size';
//	if(flag) bfs(flag, start_x, start_y,len_y);
//	else bfs(flag, start_x, start_y, len_x);
//}
//
//int f(int a, int b)
//{
//	while (b--) a *= 2;
//	return a;
//}
//
//void set()
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			map[i][j] = '*';
//			//printf("%d %d\n", i, j);
//		}
//	}
//}
//
//void print()
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			putchar(map[i][j]);
//		}
//		putchar(10);
//	}
//}