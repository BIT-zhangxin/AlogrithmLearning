//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int cmp(const void *a, const void *b)
//{
//	char *x = (char *)a;
//	char *y = (char *)b;
//	while (1)
//	{
//		int x_len = strlen(x);
//		int y_len = strlen(y);
//		int min = (x_len > y_len) ? y_len : x_len;
//		for (int i = 0; i < min; i++)
//		{
//			if (*(x + i) > *(y + i)) return -1;
//			else if (*(x + i) < *(y + i)) return 1;
//		}
//		if (x_len > y_len)
//		{
//			x += min;
//		}
//		else if (x_len < y_len)
//		{
//			y += min;
//		}
//		else return 0;
//	}
//}
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		char A[105][6];
//		int N;
//		scanf("%d", &N);
//		for (int i = 0; i < N; i++)
//		{
//			scanf("%s", A[i]);
//		}
//		qsort(A, N, sizeof(A[0]), cmp);
//		if (A[0][0] == '0')
//		{
//			printf("0\n");
//			continue;
//		}
//		for (int i = 0; i < N; i++)
//		{
//			int len = strlen(A[i]);
//			for (int j = 0; j < len; j++)
//				printf("%c", A[i][j]);
//		}
//		putchar(10);
//	}
//	return 0;
//}