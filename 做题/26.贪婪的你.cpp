//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int val;
//	int time;
//}node;
//
//int cmp(const void *a, const void *b)
//{
//	if ((*(node *)a).val != (*(node *)b).val)
//		return (*(node *)b).val - (*(node *)a).val;
//	else return (*(node *)b).time - (*(node *)a).time;
//}
//
//node stu[10005];
//int vis[10005] = { 0 };
//int main()
//{
//	int n, ans = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &stu[i].val);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &stu[i].time);
//	}
//	qsort(stu, n, sizeof(node), cmp);
//	vis[0] = 1;
//	for (int i = 0; i < n;)
//	{
//		if (!vis[stu[i].time])
//		{
//			ans += stu[i].val;
//			vis[stu[i].time] = 1;
//			i++;
//		}
//		else
//		{
//			if (!stu[i].time) i++;
//			else stu[i].time--;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}