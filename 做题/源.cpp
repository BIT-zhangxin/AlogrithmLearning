//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//class Base
//{
//public:
//	int data;
//	Base()
//	{
//		data = 0;
//	}
//	Base(int n)
//	{
//		data = n;
//	}
//	Base(int n, int m)
//	{
//		data = max(m, n);
//	}
//};
//
//class Parent
//{
//public:
//	Base test1;
//	Base test2;
//	Base test3;
//	Parent() = default;
//	Parent(int a, int b, int c) :test1(a), test2(b), test3(c)
//	{
//
//	}
//	
//	Parent(int a1, int a2, int b1, int b2, int c1, int c2) :test1(a1, a2), test2(b1, b2), test3(c1, c2)
//	{
//
//	}
//	~Parent()
//	{
//		cout << test1.data << endl;
//		cout << test2.data << endl;
//		cout << test3.data << endl;
//	}
//};
//
//int main()
//{
//	Parent(1, 2, 3, 4, 5, 6);
//}