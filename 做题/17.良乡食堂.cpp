//#include <stdio.h>
//#include <stdlib.h>
//#define MAXN 100005
//int cmp(const void *a, const void *b)
//{
//	return *(int *)a - *(int *)b;
//}
//
//int x[MAXN];
//int y[MAXN];
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d", &x[i], &y[i]);
//	}
//	qsort(x, n, 4, cmp);
//	qsort(y, n, 4, cmp);
//	int tx = x[n / 2];
//	int ty = y[n / 2];
//	long long xans = 0;
//	long long yans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		xans += (x[i] - tx > 0) ? x[i] - tx : -x[i] + tx;
//		yans += (y[i] - ty > 0) ? y[i] - ty : -y[i] + ty;
//	}
//	printf("%lld\n", xans + yans);
//	return 0;
//}