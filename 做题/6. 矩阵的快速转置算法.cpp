//#include <stdio.h>
//#include <stdlib.h>
//
//int A[1000][3] = { 0 };
//int B[1000][3] = { 0 };
//
//int main()
//{
//	int m, n, k;
//	scanf("%d%d%d", &m, &n, &k);
//	int *num = (int *)calloc(sizeof(int), n + 1);
//	int *cpot = (int *)calloc(sizeof(int), n + 1);
//	for (int i = 0; i < k; i++)
//	{
//		scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);
//	}
//	for (int i = 0; i < k; i++)
//	{
//		num[A[i][1]]++;
//	}
//	cpot[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		cpot[i] = cpot[i - 1] + num[i - 1];
//	}
//	int *list = (int *)calloc(sizeof(int), n);
//	for (int i = 0; i < k; i++)
//	{
//		int tmp = cpot[A[i][1]] + list[A[i][1]] - 1;
//		B[tmp][0] = A[i][1];
//		B[tmp][1] = A[i][0];
//		B[tmp][2] = A[i][2];
//		list[A[i][1]]++;
//	}
//	printf("num:");
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d,", num[i]);
//	}
//	putchar(10);
//	printf("cpot:");
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d,", cpot[i]);
//	}
//	putchar(10);
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d,%d,%d\n", B[i][0], B[i][1], B[i][2]);
//	}
//	return 0;
//}