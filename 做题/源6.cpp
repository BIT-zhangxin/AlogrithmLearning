//#include <cstdio>
//#include <math.h>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//double linear_function(double x)
//{
//	return 3 * x - 1;
//}
//
//double two_square_function(double x)
//{
//	return x * x;
//}
//
//double sin_function(double x)
//{
//	return sin(x);
//}
//
//double integration(double x, double y, double(*function)(double x), int precision = 100)
//{
//	double len = y - x;
//	double interval = 1.0 / precision;
//	int N = (int)(len / interval);
//	double result = 0;
//	for (int i = 0; i < N; i++)
//	{
//		result += function(x + i * interval) * interval;
//	}
//	return result;
//}
//
//int main()
//{
//	printf("%lf\n", integration(0, 10, linear_function));
//	printf("%lf\n", integration(0, 10, two_square_function), 1000);
//	printf("%lf\n", integration(0, 10, sin_function), 10000);
//	return 0;
//}