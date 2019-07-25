//#include <stdio.h>
//
//#define MAXN 65536
//
//struct node
//{
//	int time;
//	unsigned char s[5];
//}c[MAXN];
//
//int main()
//{
//	for (int i = 0; i < MAXN; i++)
//	{
//		c[i].time = 0;
//	}
//	unsigned char x, i, j, k;
//	while (scanf("%c", &x) != EOF)
//	{
//		if (!(x >> 7)) continue;
//		else
//		{
//			int tmp = 0;
//			if ((x >> 5) == 6)
//			{
//				scanf("%c", &i);
//				tmp = ((x & 31) << 6) + (i & 63);
//				c[tmp].time++;
//				c[tmp].s[0] = x;
//				c[tmp].s[1] = i;
//				c[tmp].s[2] = 0;
//			}
//			else if ((x >> 4) == 14)
//			{
//				scanf("%c", &i);
//				scanf("%c", &j);
//				tmp = ((x & 15) << 12) + ((i & 63) << 6) + (j & 63);
//				c[tmp].time++;
//				c[tmp].s[0] = x;
//				c[tmp].s[1] = i;
//				c[tmp].s[2] = j;
//				c[tmp].s[3] = 0;
//			}
//			else if ((x >> 3) == 31)
//			{
//				scanf("%c", &i);
//				scanf("%c", &j);
//				scanf("%c", &k);
//				tmp = ((x & 7) << 18) + ((i & 63) << 12) + ((j & 63) << 6) + (k & 63);
//				c[tmp].time++;
//				c[tmp].s[0] = x;
//				c[tmp].s[1] = i;
//				c[tmp].s[2] = j;
//				c[tmp].s[3] = k;
//				c[tmp].s[4] = 0;
//			}
//		}
//	}
//	int flag = 1;
//	for (int i = 1; i <= MAXN; i++)
//	{
//		if (c[i].time > 1)
//		{
//			printf("%s %#06x %d\n", c[i].s, i, c[i].time);
//			flag = 0;
//		}
//	}
//	if (flag)
//	{
//		printf("No repeat!\n");
//	}
//	return 0;
//}