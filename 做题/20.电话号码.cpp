//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void *a, const void *b)
//{
//	return *(int *)a - *(int *)b;
//}
//
//unsigned int save[62500] = { 0 };
//unsigned int map[1501] = { 0 };
//
//int check(char *p)
//{
//	int ans = 0;
//	while (*p != 0)
//	{
//		if (*p >= '0'&&*p <= '9') ans = ans * 10 + *p-'0';
//		else if (*p >= 'A'&&*p <= 'Z')
//		{
//			if (*p - 'A' < 3) ans = ans * 10 + 2;
//			else if (*p - 'A' < 6) ans = ans * 10 + 3;
//			else if (*p - 'A' < 9) ans = ans * 10 + 4;
//			else if (*p - 'A' < 12) ans = ans * 10 + 5;
//			else if (*p - 'A' < 15) ans = ans * 10 + 6;
//			else if (*p - 'A' == 16) return -1;
//			else if (*p - 'A' < 19) ans = ans * 10 + 7;
//			else if (*p - 'A' < 22) ans = ans * 10 + 8;
//			else if (*p - 'A' < 25) ans = ans * 10 + 9;
//			else if (*p - 'A' == 25) return -1;
//		}
//		p++;
//	}
//	return ans;
//}
//
//void print(int x)
//{
//	int time = x & 1023;
//	x = x >> 10;
//	if (x < 1000000)
//	{
//		putchar('3');
//		printf("%02d", x / 10000);
//	}
//	else
//	{
//		putchar('6');
//		printf("%02d", x / 10000 % 100);
//	}
//	x -= x / 10000 * 10000;
//	printf("-%04d %d\n", x, time);
//}
//
//int main()
//{
//	char tmp[21];
//	int num = 0;
//	int k = 0;
//	printf("Error:\n");
//	while (scanf("%s", tmp) != EOF)
//	{
//		int ans = check(tmp);
//		if (ans == -1 || !((ans > 2999999 && ans < 4000000) || (ans > 5999999 && ans < 7000000)))
//		{
//			printf("%s\n", tmp);
//			k = 1;
//		}
//		else
//		{
//			ans = (ans > 3999999) ? (ans - 5000000) : (ans - 3000000);
//			if (save[ans / 32] & (1 << (ans % 32)))
//			{
//				int flag = 1;
//				for (int i = 0; i < num; i++)
//				{
//					if ((map[i] ^ (ans << 10)) < 1024)
//					{
//						map[i]++;
//						flag = 0;
//						break;
//					}
//				}
//				if (flag) map[num++] += (ans << 10) + 2;
//			}
//			else save[ans / 32] ^= (1 << (ans % 32));
//		}
//	}
//	if (!k) printf("Not found.\n");
//	printf("\nDuplication:\n");
//	if (num == 0) printf("Not found.\n");
//	else
//	{
//		qsort(map, num, sizeof(int), cmp);
//		for (int i = 0; i < num; i++)
//		{
//			print(map[i]);
//		}
//	}
//	return 0;
//}