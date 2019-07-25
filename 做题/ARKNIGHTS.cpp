//#include <cstdio>
//#include <cmath>
//
//int main()
//{
//	double p = 0.02;
//	double res = 0;
//	for (int i = 1; i <= 50; i++)
//	{
//		double tmp = pow((1 - p), (i - 1)) * p * i;
//		res += tmp;
//	}
//	double N = pow((1 - p), 50);
//	for (int i = 51; i <= 99; i++)
//	{
//		double tmp = N * i;
//		for (int j = 50; j < i - 1; j++)
//		{
//			tmp *= (1 - (i - j)*p);
//		}
//		tmp *= ((i - 49)*p);
//		res += tmp;
//	}
//	printf("%lf\n", res);
//	return 0;
//}