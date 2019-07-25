//#include <stdio.h>
//#include <string.h>
//
//char A[10000][81];
//int len = 1;
//
//int cmp(char *a, char *b)
//{
//	while (*a != 0 || *b != 0)
//	{
//		if (*(a++) != *(b++)) return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	memset(A, 0, sizeof(A));
//	char x;
//	char tmp[81];
//	int t = 0;
//	while ((x = getchar()) != EOF)
//	{
//		if ((x >= 'A'&&x <= 'Z') || (x >= 'a'&&x <= 'z'))
//		{
//			tmp[t++] = x;
//		}
//		else
//		{
//			if (t == 0)
//			{
//				putchar(x);
//				continue;
//			}
//			tmp[t] = 0;
//			int flag = 0;
//			for (int i = 1; i < len; i++)
//			{
//				if (cmp(tmp, A[i]))
//				{
//					printf("%d", i);
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				strcpy(A[len++], tmp);
//				printf("%s", tmp);
//			}
//			putchar(x);
//			t = 0;
//		}
//	}
//	return 0;
//}