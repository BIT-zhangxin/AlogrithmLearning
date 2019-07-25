//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//	int num;
//	int last_num;
//	int step;
//}node;
//
//int cmp(const void *a, const void *b);
//int f(char *a, char *b);
//void print(node x);
//void BFS();
//
//node queue[100000] = { 0 };
//char dit[5003][6] = { 0 };
//char nbr[5000][5000] = { 0 };
//int vst[5003] = { 0 };
//
//int head = 0;
//int rear = 0;
//int len = 0;
//int end_num = 0;
//int max_step = 0;
//
//int main()
//{
//	char s[6], e[6];
//	scanf("%s%s", s, e);
//	strcpy(dit[0], s);
//	while (scanf("%s", dit[++len]) != EOF);
//	qsort(dit + 1, len - 1, sizeof(dit[0]), cmp);
//	for (int i = 0; i < len; i++)
//	{
//		if (!strcmp(dit[i], e))
//		{
//			end_num = i;
//			break;
//		}
//		if (i == len - 1)
//		{
//			printf("No Solution\n");
//			return 0;
//		}
//	}
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len; j++)
//		{
//			if (f(dit[i], dit[j])) nbr[i][j] = nbr[j][i] = 1;
//		}
//	}
//	BFS();
//	return 0;
//}
//
//int cmp(const void *a, const void *b)
//{
//	return strcmp((char *)a, (char *)b);
//}
//
//int f(char *a, char *b)
//{
//	int x = 0;
//	while (*a != 0)
//	{
//		if (*a++ != *b++) x++;
//		if (x > 1) return 0;
//	}
//	if (x) return 1;
//	else return 0;
//}
//
//void print(node x)
//{
//	if (x.num == 0)
//	{
//		printf("%s", dit[0]);
//		return;
//	}
//	else
//	{
//		print(queue[x.last_num]);
//		printf("->%s", dit[x.num]);
//	}
//}
//
//void BFS()
//{
//	node now, next;
//	int flag = 0;
//	while (head <= rear)
//	{
//		now = queue[head];
//		head++;
//		if (flag && now.step > max_step) break;
//		if (now.num == end_num)
//		{
//			max_step = now.step;
//			flag = 1;
//			print(now);
//			putchar(10);
//		}
//		else
//		{
//			next = now;
//			next.step++;
//			for (int i = 1; i < len; i++)
//			{
//				if (nbr[now.num][i] && (vst[i] == 0 || vst[i] == next.step))
//				{
//					vst[i] = next.step;
//					next.num = i;
//					next.last_num = head - 1;
//					queue[++rear] = next;
//				}
//			}
//		}
//	}
//	if(!flag) printf("No Solution\n");
//}
