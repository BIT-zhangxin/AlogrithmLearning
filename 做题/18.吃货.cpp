//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//int cmp(const void *a, const void *b)
//{
//	return *(int *)b - *(int *)a;
//}
//
//inline int readint() {
//	char c = getchar();
//	while (!isdigit(c)) c = getchar();
//	int x = 0;
//	while (isdigit(c)) {
//		x = x * 10 + c - '0';
//		c = getchar();
//	}
//	return x;
//}
//
//int buf[10];
//inline void writeint(int i) {
//	int p = 0;
//	if (i == 0) p++;
//	else while (i) {
//		buf[p++] = i % 10;
//		i /= 10;
//	}
//	for (int j = p - 1; j >= 0; j--) putchar('0' + buf[j]);
//}
//
//int main()
//{
//	int m, n;
//	int tmp;
//	scanf("%d%d", &m, &n);
//	if (m < 8000000 && n < 10000)
//	{
//		int B[10005] = { 0 };
//		for (int i = 0; i < n; i++)
//		{
//			tmp = readint();
//			B[i] = tmp;
//		}
//		for (int i = n; i < m; i++)
//		{
//			tmp = readint();
//			int min = 999999999;
//			int flag = 0;
//			for (int j = 0; j < n; j++)
//			{
//				if (B[j] < min)
//				{
//					min = B[j];
//					flag = j;
//				}
//			}
//			if (tmp > min)
//				B[flag] = tmp;
//		}
//		qsort(B, n, sizeof(int), cmp);
//		for (int i = 0; i < n; i++)
//		{
//			writeint(B[i]);
//			putchar(10);
//		}
//		return 0;
//	}
//	else
//	{
//		int *A = (int *)malloc(sizeof(int) * 10000000);
//		for (int i = 0; i < m; i++)
//		{
//			tmp = readint();
//			A[tmp]++;
//		}
//		int t = 0;
//		int num = 10000000;
//		for (num = 10000000; num > 0; num--)
//		{
//			if (A[num])
//			{
//				for (int j = 0; j < A[num] && t < n; j++, t++)
//				{
//					writeint(num);
//					putchar(10);
//				}
//			}
//			if (t >= n) break;
//		}
//	}
//	return 0;
//}