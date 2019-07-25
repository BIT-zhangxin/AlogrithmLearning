//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int cmp(const void *a, const void *b)
//{
//	return strcmp((char *)a, (char *)b);
//}
//
//struct node
//{
//	char x[11];
//	int vis;
//};
//
//int list[] =
//{
//1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
//16384,32768,65536,131072,262144,524288,1048576,
//2097152,4194304,8388608,16777216,33554432
//};
//
//int f(char *a, char *b);
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	struct node A[51];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", A[i].x);
//	}
//	qsort(A, n, sizeof(struct node), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		A[i].vis = 0;
//	}
//	int time = n;
//	while (time)
//	{
//		int location=-1;
//		for (int i = 0; i < n; i++)
//		{
//			if (location==-1&&A[i].vis == 0)
//			{
//				printf("%s", A[i].x);
//				A[i].vis = 1;
//				time--;
//				location = i;
//			}
//			else if(location!=-1&&f(A[location].x,A[i].x)==1)
//			{
//				printf(" %s", A[i].x);
//				A[i].vis = 1;
//				time--;
//			}
//		}
//		putchar(10);
//	}
//	return 0;
//}
//
//int f(char *a, char *b)
//{
//	int a_val = 0;
//	int b_val = 0;
//	while (*a != 0)
//	{
//		a_val += list[*a - 'a'];
//		a++;
//	}
//	while (*b != 0)
//	{
//		b_val += list[*b - 'a'];
//		b++;
//	}
//	if (a_val == b_val) return 1;
//	else return 0;
//}