//#include <stdio.h>
//#include <string.h>
//
//typedef struct
//{
//	int left;
//	int right;
//}node;
//
//typedef struct
//{
//	char ch;
//	int loction;
//}stack;
//
//node x[500005];
//stack k[500000];
//char A[500005] = { 0 };
//int top = 0;
//int num[500005] = { 0 };
//int sum = 0;
//
//int main()
//{
//	scanf("%s", A);
//	int len = strlen(A);
//	for (int i = 0; i < len; i++)
//	{
//		num[i] = sum;
//		if (A[i] == '(' || A[i] == '[')
//		{
//			if (A[i] == '[') sum++;
//			k[top].ch = A[i];
//			k[top].loction = i;
//			top++;
//		}
//		else
//		{
//			if (top == 0);
//			else if (A[i] == ')'&&k[top - 1].ch == '('|| A[i] == ']'&&k[top - 1].ch == '[')
//			{
//				x[i].left = k[top - 1].loction;
//				x[i].right = i;
//				top--;
//			}
//			else
//			{
//				top = 0;
//			}
//		}
//	}
//	int ans1 = 0;
//	int ans2 = 0;
//	int left = 0;
//	int right = 0;
//	for (int i = len - 1; i >= 0;)
//	{
//		if (x[i].right > 0)
//		{
//			while (1)
//			{
//				if (x[i].left == 0) break;
//				else if (x[x[i].left - 1].right > 0)
//				{
//					x[i].left = x[x[i].left - 1].left;
//				}
//				else break;
//			}
//			if (ans1 < num[x[i].right] - num[x[i].left])
//			{
//				ans1 = num[x[i].right] - num[x[i].left];
//				ans2 = x[i].right - x[i].left;
//				left = x[i].left;
//				right = x[i].right;
//			}
//			else if (ans1 == num[x[i].right] - num[x[i].left] && ans2 < x[i].right - x[i].left)
//			{
//				ans2 = x[i].right - x[i].left;
//				left = x[i].left;
//				right = x[i].right;
//			}
//			else if (ans1 == num[x[i].right] - num[x[i].left] && ans2 == x[i].right - x[i].left&&right < x[i].right)
//			{
//				left = x[i].left;
//				right = x[i].right;
//			}
//			if (x[i].left == 0) break;
//			else i = x[i].left - 1;
//		}
//		else i--;
//	}
//	printf("%d\n", ans1);
//	if (ans1) printf("%d %d\n", left, right);
//	return 0;
//}
