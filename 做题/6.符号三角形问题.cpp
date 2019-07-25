//#include <stdio.h>
//#include <string.h>
//#define MAX 100
//
//int mtx[MAX][MAX] = { 0 };
//int assign[50] = { 0, 0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229, 0, 0, 5804913 };
//int n = 0;
//int half = 0;
//int count = 0;
//int ans = 0;
//
//void Search(int num)
//{
//	if (count > half || num * (num - 1) / 2 - count > half) return;
//	if (num > n) ans++;
//	else
//	{
//		for (int i = 0; i < 2; i++)
//		{
//			mtx[1][num] = i;
//			count += i;
//			for (int j = 2; j <= num; j++)
//			{
//				mtx[j][num - j + 1] = (mtx[j - 1][num - j + 1] ^ mtx[j - 1][num - j + 2]);
//				count += mtx[j][num - j + 1];
//			}
//			Search(num + 1);
//			for (int j = 2; j <= num; j++) count -= mtx[j][num - j + 1];
//			count -= i;
//		}
//	}
//}
//
//int main()
//{
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(mtx, 0, sizeof(mtx));
//		count = 0;
//		ans = 0;
//		half = n * (n + 1) / 2;
//		if (half % 2)
//		{
//			printf("%d\n", ans);
//		}
//		else if (n > 22)
//		{
//			printf("%d\n", assign[n]);
//		}
//		else
//		{
//			half /= 2;
//			Search(1);
//			printf("%d\n", ans);
//		}
//	}
//	return 0;
//}
//
