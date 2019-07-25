//#include <stdio.h>
//
//#define MAX 100
//#define CUTOFF 5
//int A[MAX] = { 0 };
//int A_len = 0;
//int B[MAX] = { 0 };
//int B_len = 0;
//
//void Exchange(int *Base,int i, int j)
//{
//	int tmp = Base[i];
//	Base[i] = Base[j];
//	Base[j] = tmp;
//}
//
//void Shortsort(int *Base,int left, int right)
//{
//	if (left >= right) return;
//	for (int i = left; i < right; i++)
//	{
//		int minposition = i;
//		for (int j = i; j <= right; j++)
//		{
//			if (Base[j] < Base[minposition]) minposition = j;
//		}
//		Exchange(Base,i, minposition);
//	}
//}
//
//int Median(int *Base, int left, int right)
//{
//	int mid = (left + right) / 2, median; int len = right;
//	if (Base[left] > Base[mid]) Exchange(Base, left, mid);
//	if (Base[left] > Base[right]) Exchange(Base, left, right);
//	if (Base[mid] > Base[right]) Exchange(Base, mid, right);
//	Exchange(Base, mid, right - 1);
//	median = Base[right - 1];
//	B[B_len++] = median;
//	right -= 1;
//	while (left < right) {
//		while (left < right && Base[--right] > median);
//		while (left < right && Base[++left] < median);
//		Exchange(Base, left, right);
//	}
//	left++;
//	Exchange(Base, left, len - 1);
//	return left;
//}
//
//void Qsort(int *Base, int left, int right)
//{
//	if (left >= right) return;
//	if (right - left < CUTOFF) Shortsort(Base, left, right);
//	else
//	{
//		int edge = Median(Base, left, right);
//		Qsort(Base, left, edge - 1);
//		Qsort(Base, edge + 1, right);
//	}
//}
//
//void Scanf()
//{
//	int tmp;
//	while (scanf("%d", &tmp) == 1)
//	{
//		A[A_len++] = tmp;
//	}
//}
//
//void Print()
//{
//	printf("After Sorting:\n");
//	for (int i = 0; i < A_len; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	putchar(10);
//	printf("Median3 Value:\n");
//	for (int i = 0; i < B_len; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	if (!B_len) printf("none");
//	putchar(10);
//}
//
//int main()
//{
//	Scanf();
//	Qsort(A, 0, A_len - 1);
//	Print();
//}
//
//
