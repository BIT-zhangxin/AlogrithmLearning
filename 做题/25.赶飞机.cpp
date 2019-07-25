//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int len;
//	int v;
//}node;
//node k[500003];
//
//int cmp(const void *a, const void *b)
//{
//	return (*(node *)a).v - (*(node *)b).v;
//}
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int x, w, r, n;
//		double t;
//		scanf("%d%d%d%lf%d", &x, &w, &r, &t, &n);
//		int tmp1, tmp2;
//		int all = 0;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d%d%d",&tmp1, &tmp2, &k[i].v);
//			/*if (tmp2 > tmp1)*/ k[i].len = tmp2 - tmp1;
//			//else k[i].len = tmp1 - tmp2;
//			all += k[i].len;
//		}
//		qsort(k, n, sizeof(node), cmp);
//		double ans = 0;
//		if ((double)(x - all) / (double)r >= t)
//		{
//			ans = t + ((double)(x - all) - t * (double)r) / (double)w;
//			for (int i = 0; i < n; i++)
//			{
//				ans += (double)k[i].len / (double)(k[i].v + w);
//			}
//		}
//		else
//		{
//			t -= ans = (double)(x - all) / (double)r;
//			for (int i = 0; i < n; i++)
//			{
//				if (t == 0) ans += (double)k[i].len / (double)(k[i].v + w);
//				else
//				{
//					if ((double)k[i].len / (double)(k[i].v + r) >= t)
//					{
//						ans += t + ((double)(k[i].len) - t*(double)(k[i].v + r)) / (double)(k[i].v + w);
//						t = 0;
//					}
//					else
//					{
//						t -= (double)k[i].len / (double)(k[i].v + r);
//						ans += (double)k[i].len / (double)(k[i].v + r);
//					}
//				}
//			}
//		}
//		printf("%.6lf\n", ans);
//	}
//	return 0;
//}