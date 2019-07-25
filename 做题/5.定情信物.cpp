//#include <stdio.h>
//
//int find(char *tmp, int n);
//
//int main()
//{
//	int N;
//	scanf("%d", &N);
//	char tmp[400];
//	scanf("%s", tmp);
//	printf("%d\n", find(tmp, N));
//	return 0;
//}
//
//int find(char *p, int N)
//{
//	int max = 0;
//	for (int i = 0; i < N; i++)
//	{
//		int left_num = 0;
//		int right_num = 0;
//		char left = 0;
//		for (int time = 0; time < N; time++)
//		{
//			char tmp = p[(i + time) % N];
//			if (tmp != 'w')
//			{
//				left = tmp;
//				break;
//			}
//		}
//		if (left == 0) return N;
//		char right=0;
//		for (int time = 0; time < N; time++)
//		{
//			char tmp = p[(i + N - 1 - time) % N];
//			if (tmp != 'w')
//			{
//				right = tmp;
//				break;
//			}
//		}
//		for (int time=0; time < N; time++)
//		{
//			char tmp = p[(i + time) % N];
//			if (tmp== 'w'||tmp==left)
//			{
//				left_num++;
//			}
//			else break;
//		}
//		if (left_num == N) return N;
//		for (int time = 0; time < N; time++)
//		{
//			char tmp = p[(i + N - 1-time) % N];
//			if (tmp == 'w' || tmp == right)
//			{
//				right_num++;
//			}
//			else break;
//		}
//		if (max < left_num + right_num)
//		{
//			max = left_num + right_num;
//		}
//	}
//	if (max > N) return N;
//	return max;
//}