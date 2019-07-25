//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void *a, const void *b)
//{
//	return *(int *)a - *(int *)b;
//}
//
//int A[10005];
//
//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &A[i]);
//	qsort(A, n, sizeof(int), cmp);
//	int ans = 0;
//	for (i = 1; i < n; i++)
//	{
//		int tmp = A[i - 1] + A[i];
//		for (j = i; j < n-1; j++)
//		{
//			if (tmp > A[j + 1]) A[j] = A[j + 1];
//			else break;
//		}
//		A[j] = tmp;
//		ans += tmp;
//	}
//	printf("%d\n", ans);
//	return 0;
//}