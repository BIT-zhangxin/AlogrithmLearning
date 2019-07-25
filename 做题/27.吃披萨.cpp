//#include <stdio.h>
//#define Pi 3.1415926535898
//
//double A[10005];
//
//int divide(int n, double X, int t)
//{
//	int num = 0;
//	for (int i = 0; i<n; i++)
//	{
//		num += (int)(A[i] / X);
//	}
//	if (num >= t) return 1;
//	else return 0;
//}
//int main()
//{
//	int n, t;
//	while (scanf("%d%d", &n, &t) != EOF)
//	{
//		t++;
//		double max = 0;
//		for (int i = 0; i<n; i++)
//		{
//			scanf("%lf", &A[i]);
//			A[i] = Pi*A[i] * A[i];
//			if (A[i]>max) max = A[i];
//		}
//		double left = 0, right = max;
//		int tmp = 150;
//		while (tmp--)
//		{
//			double mid = left + (right - left) / 2;
//			if (divide(n, mid, t)) left = mid;
//			else right = mid;
//		}
//		printf("%.4lf\n", right);
//	}
//	return 0;
//}