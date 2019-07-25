//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//using namespace std;
//
//typedef struct NODE
//{
//	int data;
//	int deep;
//	struct NODE *lchild;
//	struct NODE *rchild;
//}NODE, *PNODE;
//PNODE head;
//PNODE Stack[1000] = { 0 };
//int Stack_num = 0;
//
//void BuildTree(int n)
//{
//	int deep = 0;
//	if (!head)
//	{
//		head = (PNODE)calloc(sizeof(NODE), 1);
//		head->data = n;
//		head->deep = deep;
//		return;
//	}
//	PNODE now = head;
//	while (1)
//	{
//		deep++;
//		if (n < now->data)
//		{
//			if (now->lchild == NULL)
//			{
//				now->lchild = (PNODE)calloc(sizeof(NODE), 1);
//				now->lchild->data = n;
//				now->lchild->deep = deep;
//				break;
//			}
//			else now = now->lchild;
//		}
//		else
//		{
//			if (now->rchild == NULL)
//			{
//				now->rchild = (PNODE)calloc(sizeof(NODE), 1);
//				now->rchild->data = n;
//				now->rchild->deep = deep;
//				break;
//			}
//			else now = now->rchild;
//		}
//	}
//}
//
//void Scanf()
//{
//	int tmp;
//	while (1)
//	{
//		scanf("%d", &tmp);
//		if (tmp) BuildTree(tmp);
//		else return;
//	}
//}
//
//void Print(int mode, PNODE now)
//{
//	if (mode == 1)
//	{
//		for (int i = 0; i < now->deep; i++) printf("    ");
//		printf("%d", now->data);
//		putchar(10);
//	}
//	else if (mode == 2)
//	{
//		printf(" %d", now->data);
//	}
//}
//
//void InOrderTraverse(int mode)
//{
//	stack<PNODE>Stack;
//	PNODE now = head;
//	while (now)
//	{
//		Stack.push(now);
//		now = now->lchild;
//	}
//	while(!Stack.empty())
//	{
//		now = Stack.top();
//		Stack.pop();
//		Print(mode, now);
//		now = now->rchild;
//		while (now)
//		{
//			Stack.push(now);
//			now = now->lchild;
//		}
//	}
//	putchar(10);
//}
//
//int main()
//{
//	Scanf();
//	InOrderTraverse(1);
//	InOrderTraverse(2);
//}