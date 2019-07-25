//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct node
//{
//	int x;
//	int y;
//	int data;
//}node;
//
//int m1, n1, t1;
//node M[105] = { 0 };
//int M_num[105] = { 0 };
//int M_pos[105] = { 0 };
//
//int m2, n2, t2;
//node N[105] = { 0 };
//int N_num[105] = { 0 };
//int N_pos[105] = { 0 };
//
//int Q_Element_Number = 0;
//node Q[10005] = { 0 };
//
//int main()
//{
//	scanf("%d%d%d", &m1, &n1, &t1);
//	for (int i = 1; i <= t1; i++)
//	{
//		scanf("%d%d%d", &M[i].x, &M[i].y, &M[i].data);
//		M_num[M[i].x]++;
//	}
//	M_pos[1] = 1;
//	for (int i = 2; i <= m1; i++)
//	{
//		M_pos[i] = M_pos[i - 1] + M_num[i - 1];
//	}
//	scanf("%d%d%d", &m2, &n2, &t2);
//	for (int i = 1; i <= t2; i++)
//	{
//		scanf("%d%d%d", &N[i].x, &N[i].y, &N[i].data);
//		N_num[N[i].x]++;
//	}
//	N_pos[1] = 1;
//	for (int i = 2; i <= m2; i++)
//	{
//		N_pos[i] = N_pos[i - 1] + N_num[i - 1];
//	}
//
//	for (int line = 1; line <= m1; line++)
//	{
//		int tmp[105] = { 0 };
//		for (int i = 0; i < M_num[line]; i++)
//		{
//			for (int j = 0; j < N_num[M[M_pos[line] + i].y]; j++)
//			{
//				int equal_info = N[N_pos[M[M_pos[line] + i].y] + j].y;
//				tmp[equal_info] += M[M_pos[line] + i].data * N[N_pos[M[M_pos[line] + i].y] + j].data;
//			}
//		}
//		for (int i = 1; i <= n2; i++)
//		{
//			if (tmp[i] != 0)
//			{
//				Q[1 + Q_Element_Number].x = line;
//				Q[1 + Q_Element_Number].y = i;
//				Q[1 + Q_Element_Number++].data = tmp[i];
//			}
//		}
//	}
//	printf("%d\n%d\n%d\n", m1, n2, Q_Element_Number);
//	for (int i = 1; i <= Q_Element_Number; i++)
//	{
//		printf("%d,%d,%d\n", Q[i].x, Q[i].y, Q[i].data);
//	}
//	return 0;
//}