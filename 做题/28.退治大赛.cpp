//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//	int num;//����
//	int t;//�ظ�����(�������Ϊ�˴��������������ͬһ�����֣�����100000��һǧ��)
//}node;
//
//node same[100];//�����ظ�������
//int dit[312500] = { 0 };//���������Ƿ���ڵ�״̬��һ��312500*32=1e7
//int len = 0;//�ظ����ָ���
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
//				read(tmp);//����ظ����ʹ���ṹ��
//			}
//			else
//			{
//				dit[tmp / 32] |= (1 << (tmp % 32));
//				ans++;//���ظ������dit���𰸼�1
//			}
//		}
//		qsort(same, len, sizeof(node), cmp);
//		//�Խṹ������
//		for (int i = 0; i < len; i++)
//		{
//			while (same[i].t)//
//			{
//				int willing = find(same[i].num);
//				//find������Ѱ�ҵ�ǰ�ظ������ֵ�������Ŀ�λ������
//				if (willing < now)//�����now��С���϶��޷�����
//				{
//					break;
//				}
//				int k = shift(now, willing, same[i].num - willing);
//				//shift���ж��Ƿ�����same[i].num - willing
//				//�Ĳ������ƶ���willing��λ��
//				if (k > 0)//��������Ҫ��shift����-1,break
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
//		memset(same, 0, sizeof(same));//����
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
//	same[len].num = x;//�½�
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
//		if (ans == l) return now;//�᷵��now�Ѿ��ƶ�����λ��
//	}
//	return -1;
//}