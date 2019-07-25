//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char list[128][3];
//	int m, n;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		char tmp[3];
//		char x[2];
//		scanf("%s%s", tmp, x);
//		list[x[0]][0] = tmp[0];
//		list[x[0]][1] = tmp[1];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		char tmp[105];
//		scanf("%s", tmp);
//		int len = strlen(tmp);
//		for (int j = 0; j < len; j++)
//		{
//			printf("%c%c", list[tmp[j]][0], list[tmp[j]][1]);
//		}
//		putchar(10);
//	}
//	return 0;
//}