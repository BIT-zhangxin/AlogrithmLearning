//#include <cstdio>
//#include <algorithm>
//using namespace std;
///*
//bool cmp(int a,int b)
//{
//	return a>b;
//}
//*/
//struct node
//{
//	int x, y;
//};
//int cmp(const void*a, const void*b)
//{
//	if ((*(node*)a).x != (*(node*)b).x)
//		return (*(node*)a).x > (*(node*)b).x;
//	else return (*(node*)a).y > (*(node*)b).y;
//}
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n), n != 0)
//	{
//		int A[1005], B[1005];
//		int Aend = n - 1, Bend = n - 1;
//		int Astart = 0, Bstart = 0;
//		int score = 0;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &A[i]);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &B[i]);
//		}
//		qsort(A, n, sizeof(node), cmp);
//		sort(A, A + n, cmp);
//		sort(B, B + n, cmp);
//		while (n > 0)
//		{
//			n--;
//			if (A[Aend] < B[Bend])
//			{
//				score -= 200;
//				Aend--;
//				Bstart++;
//			}
//			else if (A[Aend] > B[Bend])
//			{
//				score += 200;
//				Aend--;
//				Bend--;
//			}
//			else
//			{
//				if (A[Astart] > B[Bstart])
//				{
//					score += 200;
//					Astart++;
//					Bstart++;
//				}
//				else if (A[Astart] < B[Bstart])
//				{
//					score -= 200;
//					Aend--;
//					Bstart++;
//				}
//				else
//				{
//					if (A[Aend] != B[Bstart])
//					{
//						score -= 200;
//					}
//					Aend--;
//					Bstart++;
//				}
//			}
//		}
//		printf("%d\n", score);
//	}
//	return 0;
//}