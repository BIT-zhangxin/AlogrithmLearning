//#include <stdio.h>
//#include <string.h>
//
//int d[18][65] = { 0 };
//int p[18][65] = { 0 };
//int a[18], b[18];
//int aNum, bNum;
//
//void set(int m)
//{
//	int i, t = 2;
//	aNum = 0;
//	for (i = 1; i <= m - 1; i += 2)
//	{
//		a[++aNum] = t;
//		a[++aNum] = t;
//		t += 2;
//	}
//	if ((m - 1) & 1) aNum--;
//
//	bNum = 0;
//	t = 1;
//	for (i = 1; i <= m; i += 2)
//	{
//		b[++bNum] = t;
//		b[++bNum] = t;
//		t += 2;
//	}
//	if (m & 1) bNum--;
//}
//
//int f(int m, int n)
//{
//	if (m == 1) return 1;
//	d[1][0] = 1;
//	d[1][1] = 2;
//	for (int i = 2; i <= aNum; i++)
//	{
//		d[i][0] = 1;
//		for (int j = 1; j <= a[i]; j++)
//		{
//			d[i][j] = d[i - 1][j] + d[i - 1][j - 1] * (a[i] - (j - 1));
//		}
//	}
//	p[1][0] = 1;
//	p[1][1] = 1;
//	for (int i = 2; i <= bNum; i++)
//	{
//		p[i][0] = 1;
//		for (int j = 1; j <= b[i]; j++)
//		{
//			p[i][j] = p[i - 1][j] + p[i - 1][j - 1] * (b[i] - (j - 1));
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		ans += d[aNum][i] * p[bNum][n - i];
//	}
//	return ans;
//}
//
//int main()
//{
//	int m, n;
//	while (1)
//	{
//		scanf("%d%d", &m, &n);
//		if (!m && !n) return 0;
//		set(m);
//		int ans=f(m, n);
//		printf("%d\n", ans);
//		memset(d, 0, sizeof(d));
//		memset(p, 0, sizeof(p));
//	}
//	return 0;
//}
////
////#include <iostream>
////#include <cstdio>
////#include <string.h>
////#include <algorithm>
////#include <cmath>
////#include <vector>
////#include <queue>
////#include <set>
////#include <stack>
////#include <string>
////#include <map>
////
////
////#define max(x,y) ((x)>(y)?(x):(y))
////#define min(x,y) ((x)<(y)?(x):(y))
////#define abs(x) ((x)>=0?(x):-(x))
////#define i64 long long
////#define u32 unsigned int
////#define u64 unsigned long long
////#define clr(x,y) memset(x,y,sizeof(x))
////#define CLR(x) x.clear()
////#define ph(x) push(x)
////#define pb(x) push_back(x)
////#define Len(x) x.length()
////#define SZ(x) x.size()
////#define PI acos(-1.0)
////#define sqr(x) ((x)*(x))
////
////#define FOR0(i,x) for(i=0;i<x;i++)
////#define FOR1(i,x) for(i=1;i<=x;i++)
////#define FOR(i,a,b) for(i=a;i<=b;i++)
////#define DOW0(i,x) for(i=x;i>=0;i--)
////#define DOW1(i,x) for(i=x;i>=1;i--)
////#define DOW(i,a,b) for(i=a;i>=b;i--)
////using namespace std;
////
////
////void RD(int &x) { scanf("%d", &x); }
////void RD(i64 &x) { scanf("%I64d", &x); }
////void RD(u32 &x) { scanf("%u", &x); }
////void RD(double &x) { scanf("%lf", &x); }
////void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
////void RD(i64 &x, i64 &y) { scanf("%I64d%I64d", &x, &y); }
////void RD(u32 &x, u32 &y) { scanf("%u%u", &x, &y); }
////void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
////void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
////void RD(i64 &x, i64 &y, i64 &z) { scanf("%I64d%I64d%I64d", &x, &y, &z); }
////void RD(u32 &x, u32 &y, u32 &z) { scanf("%u%u%u", &x, &y, &z); }
////void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
////void RD(char &x) { x = getchar(); }
////void RD(char *s) { scanf("%s", s); }
////void RD(string &s) { cin >> s; }
////
////
////void PR(int x) { printf("%d\n", x); }
////void PR(i64 x) { printf("%I64d\n", x); }
////void PR(u32 x) { printf("%u\n", x); }
////void PR(double x) { printf("%.4lf\n", x); }
////void PR(char x) { printf("%c\n", x); }
////void PR(char *x) { printf("%s\n", x); }
////void PR(string x) { cout << x << endl; }
////
////
////
////int n, m;
////i64 f[55][51 * 51], p[55][51 * 51];
////int a[55], b[55], aNum, bNum;
////
////void init()
////{
////	int i, t = 2;
////	aNum = 0;
////	for (i = 1; i <= n - 1; i += 2)
////	{
////		a[++aNum] = t;
////		a[++aNum] = t;
////		t += 2;
////	}
////	if ((n - 1) & 1) aNum--;
////
////	bNum = 0;
////	t = 1;
////	for (i = 1; i <= n; i += 2)
////	{
////		b[++bNum] = t;
////		b[++bNum] = t;
////		t += 2;
////	}
////	if (n & 1) bNum--;
////}
////
////
////void DP()
////{
////	int i, j, k;
////
////
////	f[1][0] = 1;
////	f[1][1] = 2;
////	for (i = 2; i <= aNum; i++)
////	{
////		f[i][0] = 1;
////		for (j = 1; j <= a[i]; j++)
////		{
////			f[i][j] = f[i - 1][j] + f[i - 1][j - 1] * (a[i] - (j - 1));
////		}
////	}
////
////	p[1][0] = p[1][1] = 1;
////	for (i = 2; i <= bNum; i++)
////	{
////		p[i][0] = 1;
////		for (j = 1; j <= b[i]; j++)
////		{
////			p[i][j] = p[i - 1][j] + p[i - 1][j - 1] * (b[i] - (j - 1));
////		}
////	}
////	if (n == 1)
////	{
////		puts("1");
////		return;
////	}
////	i64 ans = 0;
////	for (i = 0; i <= m; i++) ans += f[aNum][i] * p[bNum][m - i];
////	PR(ans);
////}
////
////
////int main()
////{
////	RD(n, m);
////	init();
////	DP();
////	return 0;
////}