//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//#define NUM 105
//
//typedef struct NODE
//{
//	int num;
//	int last_num;
//	int dis;
//}NODE;
//
//NODE Queue[1000] = { 0 };
//int head = 0, rear = 0;
//
//char name[NUM][20] = { 0 };
//
//int map1[NUM][NUM] = { 0 };
//int map2[NUM][NUM] = { 0 };
//
//int visit[NUM] = { 0 };
//int max_dis[NUM] = { 0 };
//
//char path[NUM][NUM] = { 0 };
//int path_number = 0;
//
//int m = 0;
//int NO_TOPOLOGICAL_PATH = 0;
//
//int cmp(const void *a, const void *b)//字符串排序，从小到大
//{
//	return strcmp((char *)a, (char *)b);
//}
//
//int judge(int x)//返回x是否有入度，是返回0，否返回1
//{
//	if (visit[x]) return 0;
//	for (int i = 0; i < m; i++)
//	{
//		if (map1[i][x]) return 0;
//	}
//	return 1;
//}
//
//int find()//返回从小到大第一个入度为0的节点
//{
//	for (int i = 0; i < m; i++)
//	{
//		if (visit[i]) continue;
//		if (judge(i)) return i;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		if (!visit[i]) return -1;//无入度为0但有未访问的节点，证明有环路
//	}
//	return -2;//所有节点搜索完毕
//}
//
//void Delete(int x)//删除地图中x所有的出度
//{
//	for (int i = 0; i < m; i++)
//	{
//		map1[x][i] = 0;
//	}
//}
//
//void print_order()
//{
//	if (!judge(0))
//	{
//		NO_TOPOLOGICAL_PATH = 1;
//		return;
//	}
//	strcat(path[path_number], name[0]);
//	visit[0] = 1;
//	Delete(0);
//	while (1)
//	{
//		int now = find();
//		if (now == -2) break;
//		else if (now == -1)
//		{
//			NO_TOPOLOGICAL_PATH = 1;
//			return;
//		}
//		strcat(path[path_number], "-");
//		strcat(path[path_number], name[now]);
//		visit[now] = 1;
//		Delete(now);
//	}
//}
//
//void print(NODE N)
//{
//	if (N.num == 0) strcat(path[path_number], name[0]);
//	else
//	{
//		print(Queue[N.last_num]);
//		strcat(path[path_number], "-");
//		strcat(path[path_number], name[N.num]);
//	}
//}
//
//void print_path(int max_dis)//将等于max_dis距离的路径找出（放入path中）
//{
//	NODE now, next;
//	while (head <= rear)
//	{
//		now = Queue[head++];
//		if (now.dis == max_dis)
//		{
//			print(now);
//			path_number++;
//		}
//		else
//		{
//			for (int i = 0; i < m; i++)
//			{
//				if (map2[now.num][i])
//				{
//					next.last_num = head - 1;
//					next.num = i;
//					next.dis = now.dis + map2[now.num][i];
//					Queue[++rear] = next;
//				}
//			}
//		}
//	}
//	qsort(path, path_number, sizeof(path[0]), cmp);
//	for (int i = 0; i < path_number; i++)
//	{
//		printf("%s\n", path[i]);
//	}
//}
//
//int max_distance()//BFS计算最大距离
//{
//	queue<int>q;
//	q.push(0);
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//		for (int i = 0; i < m; i++)
//		{
//			if (map2[now][i])
//			{
//				q.push(i);
//				if (max_dis[i] < max_dis[now] + map2[now][i])
//				{
//					max_dis[i] = max_dis[now] + map2[now][i];
//				}
//			}
//		}
//	}
//	return max_dis[m - 1];
//}
//
//int main()
//{
//	int n;
//	scanf("%d,%d%*c", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		char tmp;
//		int len = 0;
//		while (1)
//		{
//			scanf("%c", &tmp);
//			if (tmp == ',')
//			{
//				name[i][len] = 0;
//				break;
//			}
//			name[i][len++] = tmp;
//		}
//	}
//	getchar();
//	int tmp1, tmp2, tmp3;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("<%d,%d,%d>%*c", &tmp1, &tmp2, &tmp3);
//		map1[tmp1][tmp2] = 1;
//		map2[tmp1][tmp2] = tmp3;
//	}
//	print_order();
//	if (NO_TOPOLOGICAL_PATH)
//	{
//		printf("NOT OPOLOGICAL PATH\n");
//		return 0;
//	}
//	printf("%s\n", path[0]);
//	memset(path[0], 0, sizeof(path[0]));
//	print_path(max_distance());
//	return 0;
//}