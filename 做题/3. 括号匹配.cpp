//#include <stdio.h>
//#include "LINKLIST.h"
//
//int main()
//{
//	LINKLIST<char>q;
//	char tmp;
//	bool ans = true;
//	while (scanf("%c", &tmp) != EOF&&tmp != '\n')
//	{
//		if (tmp == '(')
//		{
//			q.push_front(tmp);
//		}
//		else if (tmp == '[')
//		{
//			q.push_front(tmp);
//		}
//		else if (tmp == ')')
//		{
//			if (q.front() != '(')
//			{
//				ans = false;
//			}
//			else
//			{
//				q.pop();
//			}
//		}
//		else if (tmp == ']')
//		{
//			if (q.front() != '[')
//			{
//				ans = false;
//			}
//			else
//			{
//				q.pop();
//			}
//		}
//	}
//	if (!q.empty()) ans = false;
//	if (ans) printf("Match succeed!\n");
//	else printf("Match false!\n");
//	return 0;
//}