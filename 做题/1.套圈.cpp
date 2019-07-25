//#include <cstdio>
//#include <cstdlib>
//#include <math.h>
//using namespace std;
//
//#define INF 1<<30
//
//struct Node
//{
//	double x;
//	double y;
//};
//
//Node map[100000] = { 0 };
//Node tmpNode[100000] = { 0 };
//int num = 0;
//
//int cmp1(const void *a, const void *b)
//{
//	if (((Node *)a)->x != ((Node *)b)->x) return ((Node *)a)->x > ((Node *)b)->x;
//	else return ((Node *)a)->y < ((Node *)b)->y;
//}
//
//int cmp2(const void *a, const void *b)
//{
//	return ((Node *)a)->y < ((Node *)b)->y;
//}
//
//double distance(Node X, Node Y)
//{
//	return sqrt((X.x - Y.x) * (X.x - Y.x) + (X.y - Y.y) * (X.y - Y.y));
//}
//
//double f(int left, int right)
//{
//	if (right - left == 0)
//		return INF;
//	if (right - left == 1) 
//		return distance(map[left], map[right]);
//	if (right - left == 2) 
//		return fmin(fmin(distance(map[left], map[left + 1]), distance(map[left], map[right])), distance(map[left + 1], map[right]));
//	else
//	{
//		int mid = (left + right) / 2;
//		double d = fmin(f(left, mid), f(mid + 1, right));
//		for (int i = left; i <= right; i++)
//		{
//			if (fabs(map[i].x - map[mid].x) < d) tmpNode[num++] = map[i];
//		}
//		qsort(tmpNode, num, sizeof(Node), cmp2);
//		for (int i = 0; i < num; i++)
//		{
//			for (int j = i + 1; j < num&&fabs(tmpNode[j].y - tmpNode[i].y) < d; j++)
//			{
//				d = fmin(d, distance(tmpNode[i], tmpNode[j]));
//			}
//		}
//		num = 0;
//		//for (int i = 1; mid - i >= left && fabs(map[mid].x - map[mid - i].x) < d; i++)
//		//{
//		//	//int tmp = 6;
//		//	int num = 0;
//		//	for (int j = 1; mid + j <= right /*&& tmp > 0*/ && fabs(map[mid].x - map[mid + j].x) < d; j++)
//		//	{
//		//		if (fabs(map[mid].y - map[mid + j].y) < d)
//		//		{
//		//			tmpNode[num++] = map[mid + j]; 
//		//			//tmp--;
//		//			//d = fmin(d, distance(map[mid], map[mid + j]));
//		//		}
//		//	}
//		//	qsort(tmpNode, num, sizeof(Node), cmp2);
//		//	for (int k = 0; k < num; k++)
//		//	{
//		//		d = fmin(d, distance(map[mid], tmpNode[k]));
//		//	}
//		//}
//		return d;
//	}
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) && n != 0)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%lf%lf", &map[i].x, &map[i].y);
//		}
//		qsort(map, n, sizeof(Node), cmp1);
//		double ans = f(0, n - 1) / 2;
//		printf("%.2lf\n", ans);
//	}
//	return 0;
//}