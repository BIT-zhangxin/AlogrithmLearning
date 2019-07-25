//#include <stdio.h>
//#include <stdlib.h>
//#include "LINKLIST.h"
//
//int value(char x);
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	LINKLIST<char>q;
//	while (1)
//	{
//		
//		char tmp;
//		scanf("%c", &tmp);
//		if (tmp == '#')
//		{
//			while (!q.empty())
//			{
//				if (q.front() != '('&&q.front() != ')') printf("%c", q.front());
//				q.pop();
//			}
//			printf("\n");
//			n--;
//			if (!n) break;
//			continue;
//		}
//		else if ('a' <= tmp&&tmp <= 'z' || 'a' <= tmp&&tmp <= 'z')
//		{
//			printf("%c", tmp);
//		}
//		else if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^' || tmp == '(' || tmp == ')')
//		{
//			if (tmp == '(')
//			{
//				q.push_front(tmp);
//			}
//			else if (tmp == ')')
//			{
//				while (q.front() != '(')
//				{
//					printf("%c", q.front());
//					q.pop();
//				}
//				q.pop();
//			}
//			else if (q.empty() || value(q.front()) < value(tmp))
//			{
//				q.push_front(tmp);
//			}
//			else if(value(q.front()) >= value(tmp))
//			{
//				while (!q.empty() && value(q.front()) >= value(tmp))
//				{
//					if (q.front() == '^'&&tmp == '^') break;
//					printf("%c", q.front());
//					q.pop();
//				}
//				q.push_front(tmp);
//			}
//		}
//	}
//	return 0;
//}
//
//int value(char x)
//{
//	if (x == '(') return 0;
//	else if (x == '+' || x == '-') return 1;
//	else if (x == '*' || x == '/') return 2;
//	else if (x == '^') return 3;
//}