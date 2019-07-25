//#include <cstdio>
//#include <queue>
//using namespace std;
//
//int cmp(const void *a, const void *b)
//{
//	return *((int *)a) > *((int *)b);
//}
//
//typedef struct NODE
//{
//	int len;
//	int link[12];
//}NODE;
//
//NODE node[10] = { 0 };
//char visit[10] = { 0 };
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int tmp1, tmp2;
//	while (1)
//	{
//		scanf("%d", &tmp1);
//		if (tmp1 == -1) break;
//		scanf("%d", &tmp2);
//		node[tmp1].link[node[tmp1].len++] = tmp2;
//		node[tmp2].link[node[tmp2].len++] = tmp1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		qsort(node[i].link, node[i].len, sizeof(int), cmp);
//	}
//	queue<int>q;
//	for (int i = 0; i < n; i++)
//	{
//		if (visit[i]) continue;
//		q.push(i);
//		printf("%d", i);
//		visit[i] = 1;
//		while (!q.empty())
//		{
//			int now = q.front();
//			q.pop();
//			for (int j = 0; j < node[now].len; j++)
//			{
//				int next = node[now].link[j];
//				if (visit[next]) continue;
//				q.push(next);
//				printf("-%d", next);
//				visit[next] = 1;
//			}
//		}
//		putchar(10);
//	}
//	return 0;
//}