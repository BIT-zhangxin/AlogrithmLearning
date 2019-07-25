//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//#define INF 0x7fffffff
//#define T 2001
//
//int n, head[2005], q[2005], dis[2005], from[2005];
//int a[1005], mp[1001][1001], cnt, ans;
//
//bool inq[2005];
//
//struct data { int from, to, next, v, c; }e[100001];
//
//void ins(int u, int v, int w, int c)
//{
//	cnt++;
//	e[cnt].from = u; e[cnt].to = v;
//	e[cnt].v = w; e[cnt].c = c;
//	e[cnt].next = head[u]; head[u] = cnt;
//}
//
//void insert(int u, int v, int w, int c)
//{
//	ins(u, v, w, c);
//	ins(v, u, 0, -c);
//}
//
//bool spfa()
//{
//	for (int i = 0; i <= T; i++) dis[i] = INF;
//	int t = 0, w = 1, i, now;
//	dis[0] = q[0] = 0; inq[0] = 1;
//	while (t != w)
//	{
//		now = q[t]; t++; if (t == 2001)t = 0;
//		for (int i = head[now]; i; i = e[i].next)
//		{
//			if (e[i].v&&dis[e[i].to] > dis[now] + e[i].c)
//			{
//				from[e[i].to] = i;
//				dis[e[i].to] = dis[now] + e[i].c;
//				if (!inq[e[i].to])
//				{
//					inq[e[i].to] = 1;
//					q[w++] = e[i].to;
//					if (w == 2001)w = 0;
//				}
//			}
//		}
//		inq[now] = 0;
//	}
//	if (dis[T] == INF) return 0;
//	return 1;
//}
//
//void mcf()
//{
//	int i, x = INF;
//	i = from[T];
//	while (i)
//	{
//		x = min(e[i].v, x);
//		i = from[e[i].from];
//	}
//	i = from[T];
//	while (i)
//	{
//		e[i].v -= x;
//		e[i ^ 1].v += x;
//		ans += x * e[i].c;
//		i = from[e[i].from];
//	}
//}
//
//void build(int k)
//{
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//	ans = 0;
//	for (int i = 1; i <= n; i++) insert(0, i, 1, 0);
//	for (int i = 1; i <= n; i++) insert(n + i, T, 1, 0);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			insert(i, j + n, 1, k*mp[i][j]);
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			scanf("%d", &mp[i][j]);
//	build(1);
//	while (spfa())mcf();
//	printf("%d\n", ans);
//	/*build(-1);
//	while (spfa())mcf();
//	printf("%d", -ans);*/
//	return 0;
//}
//
////#include <cstdio>
////#include <cstring>
////#include <queue>
////using namespace std;
////
////typedef struct Node
////{
////	int Depth;
////	int Actual_Value;
////	int Estimate_Value;
////	int Bit_Check;
////	friend bool operator <(struct Node A, struct Node B)
////	{
////		return A.Actual_Value + A.Estimate_Value > B.Actual_Value + A.Estimate_Value;
////	}
////}NODE;
////
////int Binary[20] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288 };
////int Matrix[21][21] = { 0 };
////
////int Find(int n, int Bit_Check, int line_number)
////{
////	int ans = 0;
////	for (int i = 0; i < n; i++)
////	{
////		if ((Bit_Check&Binary[i]) == 0)
////		{
////			if (ans == 0) ans = Matrix[i][line_number];
////			else ans = min(ans, Matrix[i][line_number]);
////		}
////	}
////	return ans;
////}
////
////int main()
////{
////	int n;
////	scanf("%d", &n);
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < n; j++)
////		{
////			scanf("%d", &Matrix[i][j]);
////		}
////	}
////	int now_ans = 0;
////	priority_queue<NODE>q;
////	NODE Now, Next;
////	Now.Depth = 0;
////	Now.Actual_Value = 0;
////	Now.Estimate_Value = 0;
////	Now.Bit_Check = 0;
////	q.push(Now);
////	while (!q.empty())
////	{
////		Now = q.top();
////		q.pop();
////		if (now_ans != 0 && now_ans < Now.Actual_Value + Now.Estimate_Value) break;
////		if (Now.Depth == n)
////		{
////			if (now_ans == 0) now_ans = Now.Actual_Value;
////			else now_ans = min(now_ans, Now.Actual_Value);
////		}
////		Next.Depth = Now.Depth + 1;
////		for (int l = 0; l < n; l++)
////		{
////			if ((Now.Bit_Check&Binary[l]) == 0)
////			{
////				Next.Actual_Value = Now.Actual_Value + Matrix[l][Now.Depth];
////				Next.Bit_Check = Now.Bit_Check|Binary[l];
////				Next.Estimate_Value = 0;
////				for (int j = Next.Depth; j < n; j++)
////				{
////					Next.Estimate_Value += Find(n, Next.Bit_Check, j);
////				}
////				q.push(Next);
////			}
////		}
////	}
////	printf("%d\n", now_ans);
////	return 0;
////}
