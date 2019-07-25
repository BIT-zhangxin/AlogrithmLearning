//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//	int num;
//	int ac;
//	int cost;
//}node;
//
//char stu1[101][110] = { 0 };
//
//node stu[101];
//
//int cmp(const void *a, const void *b)
//{
//	if ((*(node *)a).ac == (*(node *)b).ac)
//	{
//		if((*(node *)a).cost == (*(node *)b).cost)
//		return (*(node *)a).num - (*(node *)b).num;
//		else return (*(node *)a).cost - (*(node *)b).cost;
//	}
//	else return (*(node *)b).ac - (*(node *)a).ac;
//}
//
//int main()
//{
//	int n;
//	int T = 1;
//	int time, sn, pn;
//	char tmp[4];
//	while (scanf("%d", &n), n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			stu[i].num = i;
//		}
//		while (1)
//		{
//			scanf("%d", &time);
//			if (time == 0)
//			{
//				qsort(stu + 1, n, sizeof(node), cmp);
//				printf("case %d:\n", T++);
//				int j;
//				for (int i = 0; i < 3; i += j)
//				{
//					for (j = 1; i + j <= n; j++)
//					{
//						printf("%d %d %d %d\n", stu[i + j].num, stu[i + j].ac, stu[i + j].cost, i + 1);
//						if (stu[i + j].ac != stu[i + j + 1].ac || stu[i + j].cost != stu[i + j + 1].cost) break;
//					}
//				}
//				memset(stu, 0, sizeof(stu));
//				memset(stu1, 0, sizeof(stu1));
//				break;
//			}
//			scanf("%d%d%s", &sn, &pn, tmp);
//			if (stu1[sn][pn] == -1) continue;
//			if (tmp[0] == 'n')
//			{
//				stu1[sn][pn] += 1;
//			}
//			else
//			{
//				stu[sn].cost += stu1[sn][pn] * 20 + time;
//				stu1[sn][pn] = -1;
//				stu[sn].ac++;
//			}
//		}
//	}
//}