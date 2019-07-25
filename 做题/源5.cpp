//#include <iostream>
//#include <iomanip>
//#include <math.h>
//#define EPS 1e-7
//using namespace std;
//bool isEqual(double a, double b) {
//	if (fabs(a - b)<EPS) {
//		return true;
//	}
//	return false;
//}
//
//double function(double x) {
//	return x;
//}
//
//double function_2D(double x, double y) {
//	return x * y;
//}
//
//double caculate_integration(double a, double b, double(*f)(double x), int precision = 100) {
//	double len = b - a;
//	double interval = 1.0 / precision;
//	unsigned long N = (unsigned long)len / interval;
//	double result = 0;
//	for (unsigned long i = 0; i<N; ++i) {
//		result += f(a + i * interval)*interval;
//	}
//
//	return result;
//
//}
//
//double caculate_integration_2D(double ax, double bx, double ay, double by,
//	double(*f)(double x, double y), int precision = 1000) {
//
//	double lenx = bx - ax, leny = by - ay;
//	double interval = 1.0 / precision;
//	unsigned long Nx = lenx / interval, Ny = leny / interval;
//	double result = 0;
//	for (unsigned long i = 0; i<Nx; ++i) {
//		for (unsigned long j = 0; j<Ny; ++j) {
//			result += f(ax + i * interval, ay + j * interval)*(interval*interval);
//		}
//	}
//
//	return result;
//
//}
//
//int main() {
//	cout << fixed << setprecision(6);
//
//	cout << caculate_integration(10.0, 15.0, function) << endl;
//	cout << caculate_integration(10.0, 15.0, function, 1000) << endl;
//	cout << caculate_integration(10.0, 15.0, function, 10000) << endl;
//
//	cout << caculate_integration(1.0, 10.0, exp, 10000) << endl;
//
//
//	cout << caculate_integration_2D(10.0, 15.0, 10.0, 15.0, function_2D) << endl;
//
//	return 0;
//}