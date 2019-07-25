//#include <cstdio>
//#include <iostream>
//#include <queue>
//using namespace std;
//#define MAXN 100
//
//typedef struct
//{
//	int x;
//	int y;
//	int step;
//}node;
//
//int BFS(node start, int m, int n);
//
//char map[MAXN][MAXN] = { 0 };
//int vis[MAXN][MAXN] = { 0 };
//
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	getchar();
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%c", &map[i][j]);
//		}
//		getchar();
//	}
//	node start;
//	start.step = 0;
//	scanf("%d%d", &start.x, &start.y);
//	int ans = BFS(start, m, n);
//	if (ans == -1) printf("cannot reach\n");
//	else printf("%d\n", ans);
//	return 0;
//}
//
//
//int BFS(node start, int m, int n) //bfs搜索，返回最小步数,失败返回-1
//{
//	queue<node>q;
//	node now, next;
//	now = start;
//	if (map[now.x][now.y] == '0') return 0;
//	if (map[now.x][now.y] == '*') return -1;
//	q.push(now);
//	vis[now.x][now.y] = 1;
//	while (!q.empty())
//	{
//		now = q.front();
//		//printf("%d %d\n", now.x, now.y);
//		q.pop();
//		if (map[now.x][now.y] == '0') return now.step;
//		next.step = now.step + 1;
//		for (int i = 0; i < 4; i++)
//		{
//			next.x = now.x + dx[i];
//			next.y = now.y + dy[i];
//			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && map[next.x][next.y] != '*' && vis[next.x][next.y] == 0)
//			{
//				q.push(next);
//				vis[next.x][next.y] = 1;
//			}
//		}
//	}
//	return -1;
//}
