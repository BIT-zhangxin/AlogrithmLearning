//#include <stdio.h>
//
//int A[1005] = { 0 };
//
//int search(int m, int n);
//int judge(int m, int n, int x);
//
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	int ans = search(m, n);
//	printf("%d\n", ans);
//	return 0;
//}
//
//int search(int m, int n)
//{
//	int left = 0, right = 10000000;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (judge(m, n, mid)) right = mid-1;
//		else left = mid + 1;
//	}
//	return left;
//}
//
//int judge(int m, int n, int x)
//{
//	int time = 0;
//	int tmp = 0;
//	int i = 0;
//	while (i < m)
//	{
//		if (tmp + A[i] <= x)
//		{
//			tmp += A[i];
//			i++;
//		}
//		else
//		{
//			if (A[i] > x) return 0;
//			time++;
//			tmp = 0;
//		}
//	}
//	if (tmp != 0) time++;
//	if (time <= n) return 1;
//	else return 0;
//}
