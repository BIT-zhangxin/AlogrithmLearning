//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//	int num;//数字
//	int t;//重复次数(用这个是为了处理数据中有许多同一个数字，比如100000个一千万)
//}node;
//
//node same[100];//储存重复的数字
//int dit[312500] = { 0 };//储存数字是否存在的状态，一共312500*32=1e7
//int len = 0;//重复数字个数
//
//void read(int x);
//int find(int x);
//int shift(int now, int willing, int len);
//
//int cmp(const void *a, const void *b)
//{
//	return (*(node *)a).num - (*(node *)b).num;
//}
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int n,tmp;
//		int ans = 0;
//		int now = 0;
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &tmp);
//			if (dit[tmp / 32] & (1 << (tmp % 32)))
//			{
//				read(tmp);//如果重复，就存进结构体
//			}
//			else
//			{
//				dit[tmp / 32] |= (1 << (tmp % 32));
//				ans++;//不重复，存进dit，答案加1
//			}
//		}
//		qsort(same, len, sizeof(node), cmp);
//		//对结构体排序
//		for (int i = 0; i < len; i++)
//		{
//			while (same[i].t)//
//			{
//				int willing = find(same[i].num);
//				//find作用是寻找当前重复的数字到达最近的空位的坐标
//				if (willing < now)//如果比now还小，肯定无法满足
//				{
//					break;
//				}
//				int k = shift(now, willing, same[i].num - willing);
//				//shift是判断是否能在same[i].num - willing
//				//的步数内移动到willing的位置
//				if (k > 0)//不能满足要求shift返回-1,break
//				{
//					now = k;
//					dit[willing / 32] |= (1 << (willing % 32));
//					ans++;
//					same[i].t--;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		printf("%d\n", ans);
//		len = 0;
//		memset(dit, 0, sizeof(dit));
//		memset(same, 0, sizeof(same));//清零
//	}
//	return 0;
//}
//
//void read(int x)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (x == same[i].num)
//		{
//			same[i].t++;
//			return;
//		}
//	}
//	same[len].num = x;//新建
//	same[len].t++;
//	len++;
//}
//
//int find(int x)
//{
//	for (int i = x - 1; i >= 0; i--)
//	{
//		if ((dit[i / 32] & (1 << (i % 32))) == 0) return i;
//	}
//}
//
//int shift(int now, int willing, int l)
//{
//	int ans = 0;
//	while (now < willing - 1)
//	{
//		now++;
//		if ((dit[now / 32] & (1 << (now % 32))) == 0) ans++;
//		if (ans == l) return now;//会返回now已经移动到的位置
//	}
//	return -1;
//}