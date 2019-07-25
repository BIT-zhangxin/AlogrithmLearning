//#include <stdio.h>
//#include <stdlib.h>
//#include <queue>
//using namespace std;
//
//int cmp(void const *a, void const *b)
//{
//	return *((int *)a) < *((int *)b);
//}
//
//typedef struct NODE
//{
//	char letter;
//	int link_num;
//	int link[26];
//}NODE;
//
//NODE node[26] = { 0 };
//int len = 0;
//int visit[26] = { 0 };
//
//void BFS()
//{
//	queue<int>q;
//	int now;
//	for (int i = 0; i < len; i++)
//	{
//		if (visit[i]) continue;
//		now = i;
//		q.push(now);
//		visit[now] = 1;
//		while (!q.empty())
//		{
//			now = q.front();
//			q.pop();
//			putchar(node[now].letter);
//			for (int j = 0; j < node[now].link_num; j++)
//			{
//				if (visit[node[now].link[j]]) continue;
//				q.push(node[now].link[j]);
//				visit[node[now].link[j]] = 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char letter;
//	int tmp1, tmp2;
//	while (1)
//	{
//		scanf("%c%*c", &letter);
//		if (letter == '*') break;
//		node[len++].letter = letter;
//	}
//	while (1)
//	{
//		scanf("%d,%d", &tmp1, &tmp2);
//		if (tmp1 == -1 && tmp2 == -1) break;
//		node[tmp1].link[node[tmp1].link_num++] = tmp2;
//		node[tmp2].link[node[tmp2].link_num++] = tmp1;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		qsort(node[i].link, node[i].link_num, sizeof(int), cmp);
//	}
//	printf("the ALGraph is\n");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", node[i].letter);
//		for (int j = 0; j < node[i].link_num; j++)
//		{
//			printf(" %d", node[i].link[j]);
//		}
//		putchar(10);
//	}
//	printf("the Breadth-First-Seacrh list:");
//	BFS();
//	putchar(10);
//	return 0;
//}