//#include <cstdio>
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//#define INF -2<<29
//
//double C(double A1, double A2, char sign)
//{
//	switch (sign)
//	{
//	case '+':
//		return A1 + A2;
//	case '-':
//		return A1 - A2;
//	case '*':
//		return A1 * A2;
//	case '/':
//		if (A2 == 0) return INF;
//		else return A1 / A2;
//	default:
//		return INF;
//	}
//}
//
//bool DFS_3(double Data1)
//{
//	if (fabs(Data1 - 24) < 0.001) return true;
//	return false;
//}
//
//bool DFS_2(double Data1, double Data2, char Symbol1)
//{
//	if (Symbol1 == '-' || Symbol1 == '/')
//	{
//		if (DFS_3(C(Data1, Data2, Symbol1)) ||
//			DFS_3(C(Data2, Data1, Symbol1)))
//			return true;
//	}
//	else
//	{
//		if (DFS_3(C(Data1, Data2, Symbol1)))
//			return true;
//	}
//	return false;
//}
//
//bool DFS_1(double Data1, double Data2, double Data3, char Symbol1, char Symbol2)
//{
//	if (Symbol2 == '-' || Symbol2 == '/')
//	{
//		if (DFS_2(Data3, C(Data1, Data2, Symbol2), Symbol1) ||
//			DFS_2(Data3, C(Data2, Data1, Symbol2), Symbol1) ||
//			DFS_2(Data2, C(Data1, Data3, Symbol2), Symbol1) || 
//			DFS_2(Data2, C(Data3, Data1, Symbol2), Symbol1) || 
//			DFS_2(Data1, C(Data2, Data3, Symbol2), Symbol1) || 
//			DFS_2(Data1, C(Data3, Data2, Symbol2), Symbol1))
//			return true;
//	}
//	else
//	{
//		if (DFS_2(Data3, C(Data1, Data2, Symbol2), Symbol1) ||
//			DFS_2(Data2, C(Data1, Data3, Symbol2), Symbol1) ||
//			DFS_2(Data1, C(Data2, Data3, Symbol2), Symbol1))
//			return true;
//	}
//	return false;
//}
//
//bool DFS_0(double Data1, double Data2, double Data3, double Data4, char Symbol1, char Symbol2, char Symbol3)
//{
//	if (Symbol3 == '-' || Symbol3 == '/')
//	{
//		if (DFS_1(Data3, Data4, C(Data1, Data2, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data3, Data4, C(Data2, Data1, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data4, C(Data1, Data3, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data4, C(Data3, Data1, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data3, C(Data1, Data4, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data3, C(Data4, Data1, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data4, C(Data2, Data3, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data4, C(Data3, Data2, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data3, C(Data2, Data4, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data3, C(Data4, Data2, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data2, C(Data3, Data4, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data2, C(Data4, Data3, Symbol3), Symbol1, Symbol2))
//			return true;
//	}
//	else
//	{
//		if (DFS_1(Data3, Data4, C(Data1, Data2, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data4, C(Data1, Data3, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data2, Data3, C(Data1, Data4, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data4, C(Data2, Data3, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data3, C(Data2, Data4, Symbol3), Symbol1, Symbol2) ||
//			DFS_1(Data1, Data2, C(Data3, Data4, Symbol3), Symbol1, Symbol2))
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	char Symbol[4] = { '+','-','*','/' };
//	double Data1 = 0;
//	double Data2 = 0;
//	double Data3 = 0;
//	double Data4 = 0;
//	while (scanf("%lf%lf%lf%lf", &Data1, &Data2, &Data3, &Data4) != EOF)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				for (int k = 0; k < 4; k++)
//				{
//					if (DFS_0(Data1, Data2, Data3, Data4, Symbol[i], Symbol[j], Symbol[k]))
//					{
//						printf("yes\n");
//						goto tap;
//					}
//				}
//			}
//		}
//		printf("no\n");
//
//		tap:continue;
//	}
//	return 0;
//}