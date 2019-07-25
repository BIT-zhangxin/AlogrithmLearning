//#include <stdio.h>
//
//int n;
//
//void Exchange(int *Base, int i, int j)
//{
//	int tmp = Base[i];
//	Base[i] = Base[j];
//	Base[j] = tmp;
//}
//
//void HeapAdjust(int *Base, int s, int m)
//{
//	for (int i = 2 * s; i <= m; i *= 2)
//	{
//		if (i < m && Base[i] < Base[i + 1]) i++;
//		if (Base[s] >= Base[i]) break;
//		Exchange(Base, s, i);
//		s = i;
//	}
//}
//
//void HeapSort(int *Base)
//{
//	for (int i = n / 2; i > 0; i--)
//	{
//		HeapAdjust(Base, i, n);
//	}
//}
//
//int main() {
//	int A[1000] = { 0 };
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	HeapSort(A);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	putchar(10);
//	for (int time = 1; time <= 2; time++)
//	{
//		Exchange(A, 1, n);
//		n--;
//		HeapSort(A);
//		for (int i = 1; i <= n; i++)
//		{
//			printf("%d ", A[i]);
//		}
//		putchar(10);
//	}
//	return 0;
//}