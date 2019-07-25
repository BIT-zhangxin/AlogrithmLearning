//#include <stdio.h>
//#include <string.h>
//#define MAXN 1000005
//
//int A[MAXN];
//
//int main()
//{
//	memset(A, 0, sizeof(A));
//	int N;
//	scanf("%d", &N);
//	int tmp;
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &tmp);
//		A[tmp]++;
//	}
//	if (N == 1)
//	{
//		printf("%d\n", tmp);
//		return 0;
//	}
//	int max = 0;
//	int left = -1;
//	int right = 0;
//	for (int i = 0; i < 1000001; i++)
//	{
//		if (A[i] > 0)
//		{
//			right = i;
//			if (right - left > max&&left != -1) max = right - left;
//			left = i;
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

inline int readint() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int x = 0;
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

unsigned char station[125000] = { 0 };
int wei[8] = { 1,2,4,8,16,32,64,128 };

int main() {
	int n, tmp;
	scanf("%d", &n);
	if (n == 1) {
		scanf("%d", &tmp);
		printf("%d\n", tmp);
		return 0;
	}
	for (int i = 0; i < n; i++) {
		//scanf("%d", &tmp);
		tmp = readint();
		station[(tmp - 1) / 8] |= 1 << ((tmp - 1) % 8);
	}
	int l, r, i, j;
	int max = 0;
	for (i = 0; i < 125000; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (station[i] & wei[j])
			{
				l = 8 * i + j + 1;
				goto loop;
			}
		}
	}
loop:
	for (; i < 125000; i++)
	{
		for (; j <8; j++)
		{
			if (station[i] & wei[j])
			{
				r = 8 * i + j + 1;
				if (max < r - l) max = r - l;
				l = r;
			}
		}
		j = 0;
	}
	printf("%d\n", max);
	return 0;
}
*/