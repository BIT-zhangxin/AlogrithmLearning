//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int Left = 0;
//
//void find(int *A, int len);
//void change(int *A, int x);
//int check(int *A,int len);
//
//int cmp(const void *a, const void *b)
//{
//	return *(int*)a - *(int*)b;
//}
//
//int main()
//{
//	char tmp;
//	int size = 0;
//	int A[35];
//	memset(A, 0, sizeof(A));
//	while (scanf("%c", &tmp)!=EOF)
//	{
//		if (tmp != ' ' && tmp != '\n')
//		{
//			A[size] = 10 * A[size] + tmp - '0';
//		}
//		if (tmp == ' ')
//		{
//			size++;
//		}
//		else if (tmp == '\n')
//		{
//			size++;
//			for (int i = 0; i < size; i++)
//			{
//				printf((i != size - 1) ? "%d " : "%d\n", A[i]);
//			}
//			Left = size;
//			size=check(A,size);
//			//从后检查一次顺序
//			find(A, size);
//			size = 0;
//			memset(A, 0, sizeof(A));
//		}
//	}
//	return 0;
//}
//
//int check(int *A,int len)
//{
//	int B[35];
//	for (int i = 0; i < len; i++)
//	{
//		B[i] = A[i];
//	}
//	qsort(B,len,sizeof(int),cmp);
//	for (int i = len-1 ; i >= 0; i--)
//	{
//		if (B[i] != A[i]) return i + 1;
//	}
//	return 0;
//}
//
//void find(int *A,int len)
//{
//	if (len == 0)
//	{
//		printf("0\n");
//		return;
//	}
//	int max = -99999999;
//	int location;
//	for (int i = 0; i < len; i++)
//	{
//		if (A[i] > max)
//		{
//			location = i;
//			max = A[i];
//		}
//	}
//	if (location == 0)
//	{
//		printf("%d ", Left - len + 1);
//		change(A, len);
//		len = check(A, len);
//		find(A, len);
//	}
//	else
//	{
//		printf("%d ",Left-location );
//		change(A, location + 1);
//		len = check(A, len);
//		find(A, len);
//	}
//}
//
//void change(int *A,int x)
//{
//	for (int i = 0; i < x / 2; i++)
//	{
//		int tmp = A[i];
//		A[i] = A[x - 1 - i];
//		A[x - 1 - i] = tmp;
//	}
//}