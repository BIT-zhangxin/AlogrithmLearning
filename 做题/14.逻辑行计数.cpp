//#include <stdio.h>
//
//int judge(char);
//
//int N = 1;
//int flag[5] = { 0 };
//int logical = 0;
//int physical = 0;
//int stop = 0;
///*
//0 ((
//1  @
//2  "
//3  '
//*/
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (stop) break;
//		else judge(ch);
//	}
//	return 0;
//}
//
//int judge(char x)
//{
//	if (x == '#')
//	{
//		if (flag[2] || flag[3])
//		{
//			printf("Unterminated string in line %d.\n", physical);
//			flag[2] = 0;
//			flag[3] = 0;
//		}
//		if (flag[0])
//			printf("Unterminated block comment at end of program.\n");
//		printf("Program %d contains %d logical lines and %d physical lines.\n", N++, logical, physical);
//		for (int i = 0; i < 5; i++)
//		{
//			flag[i] = 0;
//		}
//		logical = 0;
//		physical = 0;
//		char tmp = getchar();
//		if (tmp == '#') stop = 1;
//		else if (tmp != '\n') judge(tmp);
//	}
//	else if (x == '(')
//	{
//		char tmp = getchar();
//		if (tmp == '(' && !flag[0] && !flag[1]) flag[0] = 1;
//		else judge(tmp);
//	}
//	else if (x == ')')
//	{
//		char tmp = getchar();
//		if (tmp == ')' && flag[0] && !flag[1]) flag[0] = 0;
//		else judge(tmp);
//	}
//	else if (x == '@')
//	{
//		if (!flag[0]) flag[1] = 1;
//	}
//	else if (x == '\"')
//	{
//		if (!flag[0] && !flag[1] && !flag[3])
//		{
//			flag[2] ^= 1;
//		}
//	}
//	else if (x == '\'')
//	{
//		if (!flag[0] && !flag[1] && !flag[2])
//		{
//			flag[3] ^= 1;
//		}
//	}
//	else if (x == '\n')
//	{
//		physical++;
//		if (flag[2] || flag[3])
//		{
//			printf("Unterminated string in line %d.\n", physical);
//			flag[2] = 0;
//			flag[3] = 0;
//		}
//		flag[1] = 0;
//	}
//	else if (x == ';')
//	{
//		if (!flag[0] && !flag[1] && !flag[2] && !flag[3])
//			logical++;
//	}
//}