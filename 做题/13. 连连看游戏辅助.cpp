//#include <cstdio>
//#include <queue>
//using namespace std;
//
//typedef struct node
//{
//	int x;
//	int y;
//	int step;
//}node;
//
//int map[100][100] = { 0 };
//char visit[100][100] = { 0 };
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//
//int BFS(node start,node end,int m,int n)
//{
//	if (map[start.x][start.y] != map[end.x][end.y]) return 0;
//	queue<node>q;
//	node now, next;
//	now = start;
//	now.step = 0;
//	q.push(now);
//	visit[now.x][now.y] = 1;
//	while (!q.empty())
//	{
//		now = q.front();
//		q.pop();
//		next.step = now.step + 1;
//		if (next.step > 3) continue;
//		for (int d = 0; d < 4; d++)
//		{
//			int len = 1;
//			while (1)
//			{
//				next.x = now.x + dx[d] * len;
//				next.y = now.y + dy[d] * len;
//				if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) break;
//				if (next.x == end.x&&next.y == end.y) return 1;
//				if (map[next.x][next.y]) break;
//				if (!visit[next.x][next.y])
//				{
//					q.push(next);
//					visit[next.x][next.y] = 1;
//				}
//				len++;
//			}
//		}
//	}
//	return 0;
//}
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
//	node start, end;
//	scanf("%d%d", &start.x, &start.y);
//	scanf("%d%d", &end.x, &end.y);
//	int ans = BFS(start, end, m, n);
//	if (ans) printf("TRUE\n");
//	else printf("FALSE\n");
//	return 0;
//}